
$FreeBSD$

--- formats/format_g723_1.c.orig	Sun Oct 10 15:59:18 2004
+++ formats/format_g723_1.c	Sun Oct 10 16:05:05 2004
@@ -0,0 +1,345 @@
+/*
+ * Asterisk -- A telephony toolkit for Linux.
+ *
+ * Save and read raw, headerless G723.1 Annex A data.
+ *
+ * Copyright (C) 1999, Mark Spencer <markster@linux-support.net>
+ * Copyright (C) 2003, Maxim Sobolev <sobomax@FreeBSD.org>
+ *
+ * This program is free software, distributed under the terms of
+ * the GNU General Public License
+ */
+
+#include <asterisk/lock.h>
+#include <asterisk/channel.h>
+#include <asterisk/file.h>
+#include <asterisk/logger.h>
+#include <asterisk/sched.h>
+#include <asterisk/module.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#include <stdlib.h>
+#include <sys/time.h>
+#include <stdio.h>
+#include <unistd.h>
+#include <errno.h>
+#include <string.h>
+#include <pthread.h>
+#ifdef __linux__
+#include <endian.h>
+#else
+#include <machine/endian.h>
+#endif
+
+/* Based on format_g729.c */
+
+#define TYPE_HIGH	0x0
+#define TYPE_LOW	0x1
+#define TYPE_SILENCE	0x2
+#define TYPE_DONTSEND	0x3
+#define TYPE_MASK	0x3
+
+struct ast_filestream {
+	void *reserved[AST_RESERVED_POINTERS];
+	/* This is what a filestream means to us */
+	int fd; 				/* Descriptor */
+	struct ast_frame fr;			/* Frame information */
+	char waste[AST_FRIENDLY_OFFSET];	/* Buffer for sending frames, etc */
+	char empty;				/* Empty character */
+	unsigned char g723[24];			/* One Real G723.1 Frame */
+};
+
+static long g723_tell(struct ast_filestream *);
+
+AST_MUTEX_DEFINE_STATIC(g723_lock);
+static int glistcnt = 0;
+
+static char *name = "g723";
+static char *desc = "Raw G723.1 Annex A data";
+static char *exts = "g723";
+
+static int g723_len(unsigned char buf)
+{
+	switch(buf & TYPE_MASK) {
+	case TYPE_DONTSEND:
+		return 2;
+		break;
+	case TYPE_SILENCE:
+		return 4;
+		break;
+	case TYPE_HIGH:
+		return 24;
+		break;
+	case TYPE_LOW:
+		return 20;
+		break;
+	default:
+		ast_log(LOG_WARNING, "Badly encoded G723.1 frame (%d)\n", buf & TYPE_MASK);
+	}
+	return -1;
+}
+
+static struct ast_filestream *g723_open(int fd)
+{
+	/* We don't have any header to read or anything really, but
+	   if we did, it would go here.  We also might want to check
+	   and be sure it's a valid file.  */
+	struct ast_filestream *tmp;
+	if ((tmp = malloc(sizeof(struct ast_filestream)))) {
+		memset(tmp, 0, sizeof(struct ast_filestream));
+		if (ast_mutex_lock(&g723_lock)) {
+			ast_log(LOG_WARNING, "Unable to lock g723 list\n");
+			free(tmp);
+			return NULL;
+		}
+		tmp->fd = fd;
+		tmp->fr.data = tmp->g723;
+		tmp->fr.frametype = AST_FRAME_VOICE;
+		tmp->fr.subclass = AST_FORMAT_G723_1;
+		/* datalen will vary for each frame */
+		tmp->fr.src = name;
+		tmp->fr.mallocd = 0;
+		glistcnt++;
+		ast_mutex_unlock(&g723_lock);
+		ast_update_use_count();
+	}
+	return tmp;
+}
+
+static struct ast_filestream *g723_rewrite(int fd, char *comment)
+{
+	/* We don't have any header to read or anything really, but
+	   if we did, it would go here.  We also might want to check
+	   and be sure it's a valid file.  */
+	struct ast_filestream *tmp;
+	if ((tmp = malloc(sizeof(struct ast_filestream)))) {
+		memset(tmp, 0, sizeof(struct ast_filestream));
+		if (ast_mutex_lock(&g723_lock)) {
+			ast_log(LOG_WARNING, "Unable to lock g723 list\n");
+			free(tmp);
+			return NULL;
+		}
+		tmp->fd = fd;
+		glistcnt++;
+		ast_mutex_unlock(&g723_lock);
+		ast_update_use_count();
+	} else
+		ast_log(LOG_WARNING, "Out of memory\n");
+	return tmp;
+}
+
+static void g723_close(struct ast_filestream *s)
+{
+	if (ast_mutex_lock(&g723_lock)) {
+		ast_log(LOG_WARNING, "Unable to lock g723 list\n");
+		return;
+	}
+	glistcnt--;
+	ast_mutex_unlock(&g723_lock);
+	ast_update_use_count();
+	close(s->fd);
+	free(s);
+	s = NULL;
+}
+
+static struct ast_frame *g723_read(struct ast_filestream *s, int *whennext)
+{
+	int res;
+	/* Send a frame from the file to the appropriate channel */
+	s->fr.frametype = AST_FRAME_VOICE;
+	s->fr.subclass = AST_FORMAT_G723_1;
+	s->fr.offset = AST_FRIENDLY_OFFSET;
+	s->fr.samples = 240;
+	s->fr.mallocd = 0;
+	s->fr.data = s->g723;
+	if ((res = read(s->fd, s->g723, 1)) != 1) {
+		if (res)
+			ast_log(LOG_WARNING, "Short read (%d) (%s)!\n", res, strerror(errno));
+		return NULL;
+	}
+	s->fr.datalen = g723_len(s->g723[0]);
+	if (s->fr.datalen < 0) {
+		ast_log(LOG_WARNING, "Invalid G723.1 frame!\n");
+		return NULL;
+	}
+	if (s->fr.datalen > 1 && (res = read(s->fd, s->g723 + 1, s->fr.datalen - 1)) != s->fr.datalen - 1) {
+		if (res)
+			ast_log(LOG_WARNING, "Short read (%d) (%s)!\n", res, strerror(errno));
+		return NULL;
+	}
+	*whennext = s->fr.samples;
+	return &s->fr;
+}
+
+static int g723_write(struct ast_filestream *fs, struct ast_frame *f)
+{
+	int res;
+	unsigned char *cp;
+	if (f->frametype != AST_FRAME_VOICE) {
+		ast_log(LOG_WARNING, "Asked to write non-voice frame!\n");
+		return -1;
+	}
+	if (f->subclass != AST_FORMAT_G723_1) {
+		ast_log(LOG_WARNING, "Asked to write non-G723.1 frame (%d)!\n", f->subclass);
+		return -1;
+	}
+	for (cp = f->data; cp < (unsigned char *)f->data + f->datalen; cp += res) {
+		res = g723_len(cp[0]);
+		if (res < 0) {
+			ast_log(LOG_WARNING, "Asked to write invalid G723.1 frame!\n");
+			return -1;
+		}
+	}
+	if (cp != (unsigned char *)f->data + f->datalen) {
+		ast_log(LOG_WARNING, "Invalid G723.1 data length, %d\n", f->datalen);
+		return -1;
+	}
+	if ((res = write(fs->fd, f->data, f->datalen)) != f->datalen) {
+		ast_log(LOG_WARNING, "Bad write %d: %s\n", res, strerror(errno));
+		return -1;
+	}
+	return 0;
+}
+
+static char *g723_getcomment(struct ast_filestream *s)
+{
+	return NULL;
+}
+
+static int g723_seek(struct ast_filestream *fs, long sample_offset, int whence)
+{
+	long cur, offset, max;
+	off_t coffset, moffset, soffset;
+	int res;
+	unsigned char c;
+
+	offset = 0;	/* Shut up gcc warning */
+	if (whence == SEEK_SET) {
+		offset = sample_offset;
+	} else if (whence == SEEK_CUR || whence == SEEK_FORCECUR) {
+		if ((cur = g723_tell(fs)) == -1) {
+			ast_log(LOG_WARNING, "Can't get current position!\n");
+			return -1;
+		}
+		offset = cur + sample_offset;
+	}
+	if ((moffset = lseek(fs->fd, 0, SEEK_END)) == -1) {
+		ast_log(LOG_WARNING, "Can't seek stream to an end!\n");
+		return -1;
+	}
+	if (whence == SEEK_END) {
+		if ((max = g723_tell(fs)) == -1) {
+			ast_log(LOG_WARNING, "Can't get maximum position!\n");
+			return -1;
+		}
+		offset = max - sample_offset;
+	}
+	if (offset < 0)
+		offset = 0;
+	soffset = -1;
+	for (coffset = 0; coffset < moffset && offset > 0; coffset += res) {
+		if (lseek(fs->fd, coffset, SEEK_SET) != coffset) {
+			ast_log(LOG_WARNING, "Can't seek to offset %lli!\n", coffset);
+			return -1;
+		}
+		if (read(fs->fd, &c, 1) != 1) {
+			ast_log(LOG_WARNING, "Can't read from offset %lli!\n", coffset);
+			return -1;
+		}
+		soffset = coffset;
+		if ((res = g723_len(c)) < 0) {
+			ast_log(LOG_WARNING, "Invalid G723.1 frame at offset %lli!\n", coffset);
+			return -1;
+		}
+		if (res > 1)
+			offset -= 240;
+	}
+	if (soffset != -1 && lseek(fs->fd, soffset, SEEK_SET) != soffset) {
+		ast_log(LOG_WARNING, "Can't seek to offset %lli!\n", soffset);
+		return -1;
+	}
+
+	return 0;
+}
+
+static int g723_trunc(struct ast_filestream *fs)
+{
+	/* Truncate file to current length */
+	if (ftruncate(fs->fd, lseek(fs->fd, 0, SEEK_CUR)) < 0)
+		return -1;
+	return 0;
+}
+
+static long g723_tell(struct ast_filestream *fs)
+{
+	off_t offset, coffset;
+	int res;
+	long rval;
+	unsigned char c;
+
+	offset = lseek(fs->fd, 0, SEEK_CUR);
+	rval = 0;
+	for (coffset = 0; coffset < offset; coffset += res) {
+		if (lseek(fs->fd, coffset, SEEK_SET) != coffset) {
+			ast_log(LOG_WARNING, "Can't seek to offset %llu!\n", coffset);
+			return -1;
+		}
+		if (read(fs->fd, &c, 1) != 1) {
+			ast_log(LOG_WARNING, "Can't read from offset %llu!\n", coffset);
+			return -1;
+		}
+		if ((res = g723_len(c)) < 0) {
+			ast_log(LOG_WARNING, "Invalid G723.1 frame at offset %llu!\n", coffset);
+			return -1;
+		}
+		if (res > 1)
+			rval += 240;
+	}
+	if (lseek(fs->fd, offset, SEEK_SET) != offset) {
+		ast_log(LOG_WARNING, "Can't seek to offset %llu!\n", offset);
+		return -1;
+	}
+	return rval;
+}
+
+int load_module()
+{
+	return ast_format_register(name, exts, AST_FORMAT_G723_1,
+				   g723_open,
+				   g723_rewrite,
+				   g723_write,
+				   g723_seek,
+				   g723_trunc,
+				   g723_tell,
+				   g723_read,
+				   g723_close,
+				   g723_getcomment);
+}
+
+int unload_module()
+{
+	return ast_format_unregister(name);
+}
+
+int usecount()
+{
+	int res;
+	if (ast_mutex_lock(&g723_lock)) {
+		ast_log(LOG_WARNING, "Unable to lock g723 list\n");
+		return -1;
+	}
+	res = glistcnt;
+	ast_mutex_unlock(&g723_lock);
+	return res;
+}
+
+char *description()
+{
+	return desc;
+}
+
+
+char *key()
+{
+	return ASTERISK_GPL_KEY;
+}
