--- src/lib/core/profileManager.cpp.orig	2013-12-24 19:38:41.000000000 +0200
+++ src/lib/core/profileManager.cpp	2013-12-24 19:39:06.000000000 +0200
@@ -31,6 +31,8 @@
 #endif
 
 #include <stdlib.h>
+#include <unistd.h>
+#include <sys/types.h>
 
 /** Constructor.
  *
