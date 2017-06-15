--- src/rd.h.orig	2017-01-25 12:25:17 UTC
+++ src/rd.h
@@ -38,6 +38,12 @@
 #ifndef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 200809L  /* for timespec on solaris */
 #endif
+#ifndef __XSI_VISIBLE
+#define __XSI_VISIBLE 700 /* for gettimeofday() */
+#endif
+#ifndef __BSD_VISIBLE
+#define __BSD_VISIBLE 1 /* for alloca() */
+#endif
 #endif
 
 #include <stdio.h>
