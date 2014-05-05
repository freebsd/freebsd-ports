--- process.c
+++ process.c
@@ -37,7 +37,7 @@
 #include "config.h"
 
 /* for solaris 2.1, Unixware (SVR4.2) and possibly others: */
-#ifdef SVR4
+#if defined(SVR4) && !defined(__FreeBSD__)
 # include <sys/stropts.h>
 #endif
 
