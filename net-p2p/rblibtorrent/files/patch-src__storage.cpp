--- src/storage.cpp.orig	Sat Aug 25 15:26:43 2007
+++ src/storage.cpp	Mon Sep 10 12:51:23 2007
@@ -75,9 +75,11 @@
 #include <cstdio>
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 // for getattrlist()
+#ifdef __APPLE__
 #include <sys/attr.h>
+#endif
 #include <unistd.h>
 // for statfs()
 #include <sys/param.h>
