--- lib/rcstring/list/sort_vers.cc.orig	Mon Jun 13 12:21:49 2005
+++ lib/rcstring/list/sort_vers.cc	Tue May 16 15:48:39 2006
@@ -23,6 +23,10 @@
 #include <cstring>
 #include <rcstring/list.h>
 
+#ifdef __FreeBSD__
+#include "freebsd.h"
+#endif
+
 
 static int
 cmp(const void *va, const void *vb)
