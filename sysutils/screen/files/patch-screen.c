--- screen.c.orig	2003-09-08 07:26:41.000000000 -0700
+++ screen.c	2010-01-26 15:51:49.000000000 -0800
@@ -50,7 +50,7 @@
 
 #include "config.h"
 
-#ifdef SVR4
+#if defined(SVR4) && !defined(__FreeBSD_cc_version)
 # include <sys/stropts.h>
 #endif
 
