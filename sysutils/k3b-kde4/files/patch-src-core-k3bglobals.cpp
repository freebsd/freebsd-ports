--- src/core/k3bglobals.cpp.orig	Mon Sep 29 13:16:55 2003
+++ src/core/k3bglobals.cpp	Fri Nov  7 12:35:44 2003
@@ -30,8 +30,12 @@
 
 #include <cmath>
 #include <sys/utsname.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
-
+#endif
 
 
 struct Sample {
