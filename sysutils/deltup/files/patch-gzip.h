--- gzip.h.orig		1970-01-01 05:00:00.000000000 +0500
+++ gzip.h		2008-03-10 10:38:01.000000000 +0500
@@ -0,0 +1,17 @@
+/* Copyright (C) 2007  John Whitney
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; version 2 of the License.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * Author: John Whitney <jjw@deltup.org>
+ */
+
+extern char *gzip_name;
+extern int gzip_found;
+void find_gzip_compressor();
