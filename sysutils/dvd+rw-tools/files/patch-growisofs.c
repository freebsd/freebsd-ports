--- growisofs.c.orig	2008-03-04 10:15:03.000000000 +0100
+++ growisofs.c	2013-01-15 00:53:04.894335000 +0100
@@ -409,7 +409,7 @@
 #  define _GNU_SOURCE
 # endif
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || \
-      (defined(__APPLE__) && defined(__MACH__))
+      (defined(__APPLE__) && defined(__MACH__)) || defined(__DragonFly__)
 # define off64_t	off_t
 # if !defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) || \
               __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__<1050
@@ -995,7 +995,7 @@
     goto open_rw;
 }
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #include <sys/cdio.h>
 #include <camlib.h>
@@ -2940,7 +2940,9 @@
 # ifdef __FreeBSD__
 	syscall(SYS_mlockall,3);
 # else
+#   if !defined(__DragonFly__)
 	mlockall(MCL_CURRENT|MCL_FUTURE);
+#   endif
 # endif
     } while (0);
 
