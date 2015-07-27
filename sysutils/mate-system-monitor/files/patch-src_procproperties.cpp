--- src/procproperties.cpp.orig	2015-07-02 23:46:27.000000000 +0200
+++ src/procproperties.cpp	2015-07-14 10:18:48.273918000 +0200
@@ -26,7 +26,7 @@
 #include <glibtop/procstate.h>
 #if defined (__linux__)
 #include <asm/param.h>
-#elif defined (__NetBSD__) || defined (__OpenBSD__)
+#elif defined (__NetBSD__) || defined (__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -114,7 +114,7 @@
 
     get_process_memory_info(info);
 
-#if defined (__NetBSD__) || defined (__OpenBSD__)
+#if defined (__NetBSD__) || defined (__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
     struct clockinfo cinf;
     size_t size = sizeof (cinf);
     int HZ;
