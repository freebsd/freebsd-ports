--- psutil/_psutil_bsd.c.orig	2009-09-14 21:36:29.000000000 +0800
+++ psutil/_psutil_bsd.c	2010-05-10 11:10:18.000000000 +0800
@@ -12,6 +12,7 @@
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <sys/param.h>
 #include <sys/user.h>
 #include <sys/proc.h>
 #include <sys/vmmeter.h>  /* needed for vmtotal struct */
