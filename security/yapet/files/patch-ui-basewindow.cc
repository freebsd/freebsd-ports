--- ui/basewindow.cc.orig	2013-09-17 22:04:34.000000000 +0200
+++ ui/basewindow.cc	2013-09-17 22:05:18.000000000 +0200
@@ -33,6 +33,10 @@
 # include <stdio.h>
 #endif
 
+#ifdef HAVE_STDLIB_H
+# include <stdlib.h>
+#endif
+
 #ifdef HAVE_ALGORITHM
 # include <algorithm>
 #endif
