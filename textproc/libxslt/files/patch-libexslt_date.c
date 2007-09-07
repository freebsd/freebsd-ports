--- libexslt/date.c.orig	2007-09-07 10:59:04.000000000 -0500
+++ libexslt/date.c	2007-09-07 10:59:21.000000000 -0500
@@ -28,7 +28,7 @@
 #include "config.h"
 #endif
 
-#if HAVE_LOCALTIME_R	/* _POSIX_SOURCE required by gnu libc */
+#if defined(HAVE_LOCALTIME_R) && defined(__GLIBC__)	/* _POSIX_SOURCE required by gnu libc */
 #ifndef _AIX51		/* but on AIX we're not using gnu libc */
 #define _POSIX_SOURCE
 #endif
