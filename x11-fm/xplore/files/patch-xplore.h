--- xplore.h.orig    Wed Aug 14 23:26:59 2002
+++ xplore.h    Fri Aug  8 13:17:09 2003
@@ -26,7 +26,7 @@
 #ifdef hpux
 #pragma alloca
 #else
-#if defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #pragma alloca
 #else
 #include <alloca.h>
@@ -64,7 +64,7 @@
 #ifdef USE_STATVFS
 #include <sys/statvfs.h>
 #else
-#if defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #else
