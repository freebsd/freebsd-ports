--- bogofilter-0.8.0/find_home.h	Thu Jan  1 01:00:00 1970
+++ bogofilter-0.8.0.1/find_home.h	Mon Nov 11 02:05:44 2002
@@ -0,0 +1,33 @@
+/* $Id: find_home.h,v 1.7 2002/11/11 00:03:25 m-a Exp $ */
+
+/* find_home.h -- library function to figure out the home dir of current user */
+
+#ifndef FIND_HOME_H
+#define FIND_HOME_H
+
+/* (C) 2002 by Matthias Andree <matthias.andree@gmx.de>
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of version 2 of the GNU General Public License as
+ * published by the Free Software Foundation.
+ *
+ * This program is distributed in the hope that it will be useful, but
+ * WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * General Public License for more details, it is in the file named
+ * COPYING.
+ */
+
+/*@null@*/ /*@observer@*/
+const char *
+find_home(int read_env) /*@globals errno@*/;
+
+/*@null@*/ /*@observer@*/
+const char *
+find_home_user(const char *username) /*@globals errno@*/;
+
+/*@only@*/
+char *
+tildeexpand(const char *filename) /*@globals errno@*/;
+
+#endif
