--- texk/xdvik/jfm.c.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/jfm.c
@@ -0,0 +1,143 @@
+/*========================================================================*\
+
+Copyright (C) Atsuo Kawaguchi, 1987.
+Copyright (C) 1993-2013 The Xdvik-jp project http://xdvi.sourceforge.jp/
+
+Permission is hereby granted, free of charge, to any person obtaining a copy
+of this software and associated documentation files (the "Software"), to
+deal in the Software without restriction, including without limitation the
+rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
+sell copies of the Software, and to permit persons to whom the Software is
+furnished to do so, subject to the following conditions:
+
+The above copyright notice and this permission notice shall be included in
+all copies or substantial portions of the Software.
+
+THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
+THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
+OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
+ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
+OTHER DEALINGS IN THE SOFTWARE.
+
+NOTE:
+This module is based on prior work, as noted below and
+in the modification history in README.xdvik-jp and changelog.
+
+\*========================================================================*/
+
+/*------------------------------------------------------------------------
+  The function read_jfm0() and jfm.h are derived from
+    drivers/jxdvi.NEWS/font.{c,h}
+    in ascii jtex1.7.tar.Z (1992, ASCII CORPORATION).
+  The original author and copyright notice is shown below (in UTF-8):
+
+ *
+ * Copyright (C) Atsuo Kawaguchi, 1987.
+ * 連絡先：
+ *      (...)
+ *      (...)
+ *          川口敦生
+ *        (atsuo@sanken.osaka-u.junet)
+ * このプログラムのいかなる複写、移植、改変、修正も許諾します。
+ * Everyone is permitted to do anything on this program
+ * including copying, porting, debugging, and modifying.
+ *
+
+ -------------------------------------------------------------------------*/
+
+#include "xdvi-config.h"
+#include "xdvi.h"
+#ifdef	PTEX
+
+#include "jfm.h"
+#include "util.h"
+
+#ifndef	SEEK_SET
+#define	SEEK_SET	0
+#endif
+
+/**** read_jfm0: borrowed from jxdvi-NEWS ****/
+static int read_jfm0(FILE *fp, struct jfm *j)
+{
+	int i;
+
+	fseek(fp, 0L, SEEK_SET);
+
+	/* read jfm table field. */
+	for (i = 0; i <= J_NP; i++)
+	    j->table[i] = (short) get_bytes(fp, 2);
+
+	/* read jfm header */
+	j->check_sum = get_bytes(fp, 4);
+	j->design_size = get_bytes(fp, 4);
+	fseek(fp, (long) (4 * (j->table[J_LH] - 2)), 1);
+    
+	/* read jfm char_type */
+	j->type = xmalloc(sizeof(struct jfm_char_type) * j->table[J_NT]);
+	for (i=0; i < j->table[J_NT]; i++) {
+	    j->type[i].code = (short) get_bytes(fp, 2);
+	    j->type[i].index = (short) get_bytes(fp, 2);
+	}
+    
+	/* read jfm char_info */
+	j->info = xmalloc(sizeof(struct jfm_char_info) * (j->table[J_EC] + 1));
+	for (i = 0; i <= j->table[J_EC]; i++) {
+	    j->info[i].width_ix = (unsigned char) get_byte(fp);
+	    j->info[i].height_depth_ix = (unsigned char) get_byte(fp);
+	    j->info[i].italic_ix_tag = (unsigned char) get_byte(fp);
+	    j->info[i].remainder_ix = (unsigned char) get_byte(fp);
+	}
+    
+	/* read jfm width */
+	j->width = xmalloc(sizeof(unsigned long) * j->table[J_NW]);
+	for (i = 0; i < j->table[J_NW]; i++)
+	    j->width[i] = get_bytes(fp, 4);
+
+	/* read jfm height */
+	j->height = xmalloc(sizeof(unsigned long) * j->table[J_NH]);
+	for (i = 0; i < j->table[J_NH]; i++)
+	    j->height[i] = get_bytes(fp, 4);
+
+	/* read jfm depth */
+	j->depth = xmalloc(sizeof(unsigned long) * j->table[J_ND]);
+	for (i = 0; i < j->table[J_ND]; i++)
+	    j->depth[i] = get_bytes(fp, 4);
+
+	/* read jfm italic */
+	j->italic = xmalloc(sizeof(unsigned long) * j->table[J_NI]);
+	for (i = 0; i < j->table[J_NI]; i++)
+	    j->italic[i] = get_bytes(fp, 4);
+	return 0;
+}
+
+static int jfms_max = 0;
+static int jfms_num = 0;
+static struct jfm *jfms = NULL;
+
+struct jfm *read_jfm(FILE *fp, char *fontname)
+{
+	int i;
+	struct jfm *j;
+
+	for (i=0; i<jfms_num; i++) {
+	    if (strcmp(fontname, jfms[i].fontname) == 0) return &jfms[i];
+	}
+
+	if (jfms_num == jfms_max) {
+	    if (jfms_max == 0) jfms_max = 8;
+	    else               jfms_max *= 2;
+	    jfms = xrealloc( jfms, sizeof(jfms[0]) * jfms_max );
+	}
+	j = &jfms[jfms_num];
+
+	if (read_jfm0(fp, j)) {
+	    fprintf(stderr, "Cannot open metric file: %s\n", fontname);
+	    return NULL;
+	}
+	j->fontname = xstrdup(fontname);
+	jfms_num++;
+	return j;
+}
+#endif	/* PTEX */
