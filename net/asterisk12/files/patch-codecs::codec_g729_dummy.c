
$FreeBSD$

--- /dev/null	Fri Jan 30 01:52:11 2004
+++ codecs/codec_g729_dummy.c	Fri Jan 30 01:57:59 2004
@@ -0,0 +1,275 @@
+/*
+ * Asterisk -- A telephony toolkit for Linux.
+ *
+ * Translate between signed linear and G.729 (dummy!)
+ *
+ * The G.729 code is not included in the Asterisk distribution because
+ * it is covered with patents, and in spite of statements to the contrary,
+ * the "technology" is extremely expensive to license.
+ * 
+ * Copyright (C) 1999, Mark Spencer
+ *
+ * Mark Spencer <markster@linux-support.net>
+ *
+ * This program is free software, distributed under the terms of
+ * the GNU General Public License
+ */
+
+#include <sys/types.h>
+#include <asterisk/translate.h>
+#include <asterisk/module.h>
+#include <asterisk/logger.h>
+#include <asterisk/channel.h>
+#include <pthread.h>
+#include <fcntl.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <netinet/in.h>
+#include <string.h>
+#include <stdio.h>
+
+/* Sample frame data */
+#include "slin_g729_ex.h"
+#include "g729_slin_ex.h"
+
+static ast_mutex_t localuser_lock = AST_MUTEX_INITIALIZER;
+static int localusecnt=0;
+
+static char *tdesc = "Dummy G.729/PCM16 Codec Translator";
+
+struct g729_encoder_pvt {
+	struct ast_frame f;
+	/* Space to build offset */
+	char offset[AST_FRIENDLY_OFFSET];
+	/* Buffer for our outgoing frame */
+	char outbuf[8000];
+	/* Enough to store a full second */
+	short buf[8000];
+	int tail;
+};
+
+struct g729_decoder_pvt {
+	struct ast_frame f;
+	/* Space to build offset */
+	char offset[AST_FRIENDLY_OFFSET];
+	/* Enough to store a full second */
+	short buf[8000];
+	int tail;
+};
+
+static struct ast_translator_pvt *g729tolin_new()
+{
+	struct g729_decoder_pvt *tmp;
+	tmp = malloc(sizeof(struct g729_decoder_pvt));
+	if (tmp) {
+		tmp->tail = 0;
+		localusecnt++;
+		ast_update_use_count();
+	}
+	return (struct ast_translator_pvt *)tmp;
+}
+
+static struct ast_frame *lintog729_sample()
+{
+	static struct ast_frame f;
+	f.frametype = AST_FRAME_VOICE;
+	f.subclass = AST_FORMAT_SLINEAR;
+	f.datalen = sizeof(slin_g729_ex);
+	/* Assume 8000 Hz */
+	f.samples = sizeof(slin_g729_ex)/16;
+	f.mallocd = 0;
+	f.offset = 0;
+	f.src = __PRETTY_FUNCTION__;
+	f.data = slin_g729_ex;
+	return &f;
+}
+
+static struct ast_frame *g729tolin_sample()
+{
+	static struct ast_frame f;
+	f.frametype = AST_FRAME_VOICE;
+	f.subclass = AST_FORMAT_G729A;
+	f.datalen = sizeof(g729_slin_ex);
+	/* All frames are 10 ms long */
+	f.samples = 10;
+	f.mallocd = 0;
+	f.offset = 0;
+	f.src = __PRETTY_FUNCTION__;
+	f.data = g729_slin_ex;
+	return &f;
+}
+
+static struct ast_translator_pvt *lintog729_new()
+{
+	struct g729_encoder_pvt *tmp;
+	tmp = malloc(sizeof(struct g729_encoder_pvt));
+	if (tmp) {
+		localusecnt++;
+		ast_update_use_count();
+		tmp->tail = 0;
+	}
+	return (struct ast_translator_pvt *)tmp;
+}
+
+static struct ast_frame *g729tolin_frameout(struct ast_translator_pvt *pvt)
+{
+	struct g729_decoder_pvt *tmp = (struct g729_decoder_pvt *)pvt;
+	if (!tmp->tail)
+		return NULL;
+	/* Signed linear is no particular frame size, so just send whatever
+	   we have in the buffer in one lump sum */
+	tmp->f.frametype = AST_FRAME_VOICE;
+	tmp->f.subclass = AST_FORMAT_SLINEAR;
+	tmp->f.datalen = tmp->tail * 2;
+	/* Assume 8000 Hz */
+	tmp->f.samples = tmp->tail / 8;
+	tmp->f.mallocd = 0;
+	tmp->f.offset = AST_FRIENDLY_OFFSET;
+	tmp->f.src = __PRETTY_FUNCTION__;
+	tmp->f.data = tmp->buf;
+	/* Reset tail pointer */
+	tmp->tail = 0;
+
+	return &tmp->f;	
+}
+
+static int g729tolin_framein(struct ast_translator_pvt *pvt, struct ast_frame *f)
+{
+	struct g729_decoder_pvt *tmp = (struct g729_decoder_pvt *)pvt;
+	int len = 0;
+	while(len < f->datalen) {
+		/* Assuming there's space left, decode into the current buffer at
+		   the tail location */
+		if (10 + len > f->datalen) {
+			ast_log(LOG_WARNING, "Measured length exceeds frame length\n");
+			return -1;
+		}
+		if (tmp->tail + 160 < sizeof(tmp->buf)/2) {	
+			memset(tmp->buf + tmp->tail, 0, 160);
+			tmp->tail+=160;
+		} else {
+			ast_log(LOG_WARNING, "Out of buffer space\n");
+			return -1;
+		}
+		len += 10;
+	}
+	return 0;
+}
+
+static int lintog729_framein(struct ast_translator_pvt *pvt, struct ast_frame *f)
+{
+	/* Just add the frames to our stream */
+	/* XXX We should look at how old the rest of our stream is, and if it
+	   is too old, then we should overwrite it entirely, otherwise we can
+	   get artifacts of earlier talk that do not belong */
+	struct g729_encoder_pvt *tmp = (struct g729_encoder_pvt *)pvt;
+	if (tmp->tail + f->datalen/2 < sizeof(tmp->buf) / 2) {
+		memcpy(&tmp->buf[tmp->tail], f->data, f->datalen);
+		tmp->tail += f->datalen/2;
+	} else {
+		ast_log(LOG_WARNING, "Out of buffer space\n");
+		return -1;
+	}
+	return 0;
+}
+
+static struct ast_frame *lintog729_frameout(struct ast_translator_pvt *pvt)
+{
+	struct g729_encoder_pvt *tmp = (struct g729_encoder_pvt *)pvt;
+	int cnt=0;
+	/* We can't work on anything less than a frame in size */
+	if (tmp->tail < 160)
+		return NULL;
+	tmp->f.frametype = AST_FRAME_VOICE;
+	tmp->f.subclass = AST_FORMAT_G729A;
+	tmp->f.offset = AST_FRIENDLY_OFFSET;
+	tmp->f.src = __PRETTY_FUNCTION__;
+	tmp->f.samples = 0;
+	tmp->f.mallocd = 0;
+	while(tmp->tail >= 160) {
+		/* Encode a frame of data */
+		if (cnt + 10 >= sizeof(tmp->outbuf)) {
+			ast_log(LOG_WARNING, "Out of buffer space\n");
+			return NULL;
+		}
+		memset(tmp->outbuf + cnt, 0, 10);
+		/* Assume 8000 Hz */
+		tmp->f.samples += 10;
+		cnt += 10;
+		tmp->tail -= 160;
+		/* Move the data at the end of the buffer to the front */
+		if (tmp->tail)
+			memmove(tmp->buf, tmp->buf + 160, tmp->tail * 2);
+	}
+	tmp->f.datalen = cnt;
+	tmp->f.data = tmp->outbuf;
+	return &tmp->f;	
+}
+
+static void g729_destroy(struct ast_translator_pvt *pvt)
+{
+	free(pvt);
+	localusecnt--;
+	ast_update_use_count();
+}
+
+static struct ast_translator g729tolin =
+	{ "g729tolin_dummy", 
+	   AST_FORMAT_G729A, AST_FORMAT_SLINEAR,
+	   g729tolin_new,
+	   g729tolin_framein,
+	   g729tolin_frameout,
+	   g729_destroy,
+	   g729tolin_sample
+	   };
+
+static struct ast_translator lintog729 =
+	{ "lintog729_dummy", 
+	   AST_FORMAT_SLINEAR, AST_FORMAT_G729A,
+	   lintog729_new,
+	   lintog729_framein,
+	   lintog729_frameout,
+	   g729_destroy,
+	   lintog729_sample
+	   };
+
+int unload_module(void)
+{
+	int res;
+	ast_mutex_lock(&localuser_lock);
+	res = ast_unregister_translator(&lintog729);
+	if (!res)
+		res = ast_unregister_translator(&g729tolin);
+	if (localusecnt)
+		res = -1;
+	ast_mutex_unlock(&localuser_lock);
+	return res;
+}
+
+int load_module(void)
+{
+	int res;
+	res=ast_register_translator(&g729tolin);
+	if (!res) 
+		res=ast_register_translator(&lintog729);
+	else
+		ast_unregister_translator(&g729tolin);
+	return res;
+}
+
+char *description(void)
+{
+	return tdesc;
+}
+
+int usecount(void)
+{
+	int res;
+	STANDARD_USECOUNT(res);
+	return res;
+}
+
+char *key()
+{
+	return ASTERISK_GPL_KEY;
+}
