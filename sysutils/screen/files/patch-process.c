--- process.c.orig	2003-09-18 05:53:54.000000000 -0700
+++ process.c	2010-01-26 21:27:17.000000000 -0800
@@ -37,7 +37,7 @@
 #include "config.h"
 
 /* for solaris 2.1, Unixware (SVR4.2) and possibly others: */
-#ifdef SVR4
+#if defined(SVR4) && !defined(__FreeBSD_cc_version)
 # include <sys/stropts.h>
 #endif
 
