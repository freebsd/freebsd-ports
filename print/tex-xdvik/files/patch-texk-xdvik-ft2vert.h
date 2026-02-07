--- texk/xdvik/ft2vert.h.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ft2vert.h
@@ -0,0 +1,30 @@
+/*
+ * "ft2vert.h"
+ * 
+ * (C) 2005 Nobuyuki TSUCHIMURA
+ *
+ * This file is free
+ * software; you can redistribute it and/or modify it under the terms of
+ * the GNU Library General Public License as published by the Free
+ * Software Foundation; either version 2 of the License, or (at your
+ * option) any later version.  This library is distributed in the hope
+ * that it will be useful, but WITHOUT ANY WARRANTY; without even the
+ * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
+ * PURPOSE.  See the GNU Library General Public License for more details.
+ * You should have received a copy of the GNU Library General Public
+ * License along with this library; if not, write to the Free Software
+ * Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
+ *
+ */
+
+#ifndef FT2VERT_H_
+#define FT2VERT_H_
+
+/* store GSUB feature vert/vrt2 */
+struct ft2vert_st *ft2vert_init(FT_Face face);
+
+/* convert horizontal glyph index to vertical glyph index
+ */
+FT_UInt ft2vert_get_gid(struct ft2vert_st *ft2vert, FT_UInt gid);
+
+#endif /* FT2VERT_H_ */
