
$FreeBSD$

--- formats/format_g729.c.orig	Mon Sep  8 19:48:07 2003
+++ formats/format_g729.c	Fri Jan 30 01:47:34 2004
@@ -45,7 +45,7 @@
 	struct ast_frame fr;				/* Frame information */
 	char waste[AST_FRIENDLY_OFFSET];	/* Buffer for sending frames, etc */
 	char empty;							/* Empty character */
-	unsigned char g729[20];				/* Two Real G729 Frames */
+	unsigned char g729[10];				/* One Real G729 Frame */
 };
 
 
@@ -126,11 +126,11 @@
 	s->fr.frametype = AST_FRAME_VOICE;
 	s->fr.subclass = AST_FORMAT_G729A;
 	s->fr.offset = AST_FRIENDLY_OFFSET;
-	s->fr.samples = 160;
-	s->fr.datalen = 20;
+	s->fr.samples = 80;
+	s->fr.datalen = 10;
 	s->fr.mallocd = 0;
 	s->fr.data = s->g729;
-	if ((res = read(s->fd, s->g729, 20)) != 20) {
+	if ((res = read(s->fd, s->g729, 10)) != 10) {
 		if (res)
 			ast_log(LOG_WARNING, "Short read (%d) (%s)!\n", res, strerror(errno));
 		return NULL;
@@ -150,12 +150,12 @@
 		ast_log(LOG_WARNING, "Asked to write non-G729 frame (%d)!\n", f->subclass);
 		return -1;
 	}
-	if (f->datalen % 20) {
-		ast_log(LOG_WARNING, "Invalid data length, %d, should be multiple of 20\n", f->datalen);
+	if (f->datalen % 10) {
+		ast_log(LOG_WARNING, "Invalid data length, %d, should be multiple of 10\n", f->datalen);
 		return -1;
 	}
 	if ((res = write(fs->fd, f->data, f->datalen)) != f->datalen) {
-			ast_log(LOG_WARNING, "Bad write (%d/20): %s\n", res, strerror(errno));
+			ast_log(LOG_WARNING, "Bad write (%d/10): %s\n", res, strerror(errno));
 			return -1;
 	}
 	return 0;
@@ -174,7 +174,7 @@
 	cur = lseek(fs->fd, 0, SEEK_CUR);
 	max = lseek(fs->fd, 0, SEEK_END);
 	
-	bytes = 20 * (sample_offset / 160);
+	bytes = 10 * (sample_offset / 80);
 	if (whence == SEEK_SET)
 		offset = bytes;
 	else if (whence == SEEK_CUR || whence == SEEK_FORCECUR)
@@ -202,7 +202,7 @@
 {
 	off_t offset;
 	offset = lseek(fs->fd, 0, SEEK_CUR);
-	return (offset/20)*160;
+	return (offset/10)*80;
 }
 
 int load_module()
