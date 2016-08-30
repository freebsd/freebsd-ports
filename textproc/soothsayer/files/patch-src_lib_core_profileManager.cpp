--- src/lib/core/profileManager.cpp.orig	2008-06-02 13:29:06 UTC
+++ src/lib/core/profileManager.cpp
@@ -31,6 +31,8 @@
 #endif
 
 #include <stdlib.h>
+#include <unistd.h>
+#include <sys/types.h>
 
 /** Constructor.
  *
