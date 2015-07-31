--- texk/xdvik/ptexvf.c.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ptexvf.c
@@ -0,0 +1,147 @@
+/*========================================================================*\
+
+Copyright (C) 1993 Yasuhisa Hayashi
+Copyright (C) 1999-2013 The Xdvik-jp project http://xdvi.sourceforge.jp/
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
+  This module is based on "zeit.c" in
+    "xdvi patch level 17 zeit 書体倶楽部対応化 patch"
+    xdvi-zeit (1993/8, fj.sources)
+  The original author is Yasuhisa Hayashi (林 康久, hayashi@me.aoyama.ac.jp)
+  and copyright notice is shown below (in UTF-8):
+
+○copyright
+
+    わたしが加えた部分については改変、転用、再配布すべ
+    て自由とします。
+
+ -------------------------------------------------------------------------*/
+
+/*******************************************************
+ *  Zeit Shotai Kurabu interface routine for xdvi pl.17
+ *  Written by Y. Hayashi   (hayashi@me.aoyama.ac.jp)
+ ******************************************************/
+
+#include "xdvi-config.h"
+#include "xdvi.h"
+#include "dvi-init.h"
+#include "util.h"
+
+#ifndef       X_NOT_STDC_ENV
+#include <stdlib.h>
+#endif
+
+#include "ptexmap.h"
+#include "ptexvf.h"
+#include "jfm.h"
+
+#ifdef PTEX
+#include "ft2.h"
+
+static void read_PTEXVF_char(struct font *fontp, wide_ubyte ch)
+{
+    struct glyph *g;
+    int ascend;
+
+    if (ch > fontp->maxchar) {
+	int j;
+	int i = KTABLESIZE * ((int)(ch / KTABLESIZE)+1);
+	fontp->kglyph = xrealloc(fontp->kglyph, sizeof(struct glyph *) * i);
+	for (j=fontp->maxchar+1; j<i; j++) {
+	    fontp->kglyph[j] = NULL;
+	}
+	fontp->maxchar = i-1;
+    }
+    g = fontp->kglyph[ch];
+    if (g == NULL) {
+	struct glyph *orig = fontp->kglyph[0];
+	ASSERT(orig != NULL, "Unexpected error.");
+	g = fontp->kglyph[ch] = xcalloc(1, sizeof(struct glyph));
+	g->bitmap.w = orig->bitmap.w;
+	g->bitmap.h = orig->bitmap.h;
+	g->x        = orig->x;
+	g->y        = orig->y;
+	g->dvi_adv  = orig->dvi_adv;
+    }
+    alloc_bitmap(&g->bitmap);
+    ascend = ft2_get_bitmap(ch, fontp->ft2_index, &g->bitmap);
+#ifndef WORDS_BIGENDIAN
+    order_reverse_bitmap(&g->bitmap);
+#endif  /* !WORDS_BIGENDIAN */
+    g->tdir = fontp->dir;
+    if (fontp->dir) {  /* tate */
+	int swap = g->x;
+	g->x     = g->y;
+	g->y     = swap;
+    } else {  /* yoko */
+	g->y = ascend;
+    }
+}
+
+int read_PTEXVF_index(struct font *fontp)
+{
+    int n;
+    struct glyph *g;
+    struct jfm *jfm;
+    const double dimconv = fontp->dimconv;
+
+    fontp->read_char = read_PTEXVF_char;
+    fontp->kglyph = xcalloc(KTABLESIZE, sizeof(struct glyph *));
+    fontp->maxchar = KTABLESIZE - 1;
+
+    jfm = read_jfm(fontp->file, fontp->fontname);
+    if (jfm == NULL) return -1;
+    fontp->ft2_index = ft2_open_font(getkanjifont(fontp->fontname));
+    if (fontp->ft2_index < 0) return -1;
+
+    for (n=0; n<jfm->table[J_NT]; n++) {
+	int code  =  jfm->type[n].code;
+	int index =  jfm->type[n].index;
+	int width =  jfm->width[jfm->info[index].width_ix];
+	int height= jfm->height[jfm->info[index].height_depth_ix / 0x10];
+	int depth =  jfm->depth[jfm->info[index].height_depth_ix % 0x10];
+
+	g = xcalloc(1, sizeof(struct glyph));
+	g->bitmap.w = (int)(dimconv * width) >> 16;
+	g->bitmap.h = (int)(dimconv * (height + depth)) >> 16;
+	if (g->bitmap.w != g->bitmap.h) {
+	  if (code<0xFF61 || code>0xFFDC) /* HALFWIDTH in Unicode: U+FF61 -- U+FFDC */
+	    fprintf(stderr, "Warning: '%s' (code=0x%X) is not square.\n",
+		    fontp->fontname, code);
+	}
+	g->bitmap.bits = NULL;
+	g->x = 0;
+	g->y = (int) (dimconv * height) >> 16;
+	g->dvi_adv = dimconv * width;
+	fontp->kglyph[code] = g;
+    }
+    g = fontp->kglyph[0];
+    alloc_bitmap(&g->bitmap);
+    fill_bitmap(&g->bitmap);
+    return 0;
+}
+#endif  /* PTEX */
