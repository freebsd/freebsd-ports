--- texk/xdvik/ft2.h.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ft2.h
@@ -0,0 +1,33 @@
+/*========================================================================*\
+
+Copyright (C) 2002-2013 The Xdvik-jp project http://xdvi.sourceforge.jp/
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
+This module is based on prior work, as noted in the modification history
+in README.xdvik-jp and changelog.
+
+\*========================================================================*/
+
+struct ptexmap;	/* forward declaration */
+struct bitmap;	/* forward declaration */
+
+int ft2_open_font(struct ptexmap *map);
+int ft2_get_bitmap(long char_code, int ft2_index, struct bitmap *bm);
