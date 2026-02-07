--- prnt/hpcups/ErnieFilter.cpp.orig	2022-02-23 07:41:04 UTC
+++ prnt/hpcups/ErnieFilter.cpp
@@ -50,7 +50,8 @@
 #include "ErnieFilter.h"
 
 
-#if defined(__APPLE__) || defined(__linux) || defined(__GLIBC__) || defined(__NetBSD__)
+#if defined(__APPLE__) || defined(__linux) || defined(__GLIBC__) \
+ || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <math.h>
 #endif
 
