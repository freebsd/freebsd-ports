--- libexslt/date.c.orig	Mon Jul  5 19:38:13 2004
+++ libexslt/date.c	Mon Jul  5 19:44:09 2004
@@ -28,7 +28,7 @@
 #include "config.h"
 #endif
 
-#if HAVE_LOCALTIME_R	/* _POSIX_SOURCE required by gnu libc */
+#if defined(HAVE_LOCALTIME_R) && defined(__GLIBC__)	/* _POSIX_SOURCE required by gnu libc */
 #define _POSIX_SOURCE
 #endif
 
