--- ./src/xfpm-polkit.c.orig	2011-01-07 09:23:26.000000000 -0500
+++ ./src/xfpm-polkit.c	2011-05-29 14:46:28.722111372 -0400
@@ -37,8 +37,8 @@
 #else
 #include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
 #endif
+#include <sys/user.h>
 
 #include <errno.h>
 
