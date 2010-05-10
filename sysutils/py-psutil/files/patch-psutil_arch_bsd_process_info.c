--- psutil/arch/bsd/process_info.c.orig	2009-09-15 05:45:29.000000000 +0800
+++ psutil/arch/bsd/process_info.c	2010-05-10 11:10:37.000000000 +0800
@@ -13,6 +13,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <sys/param.h>
 #include <sys/user.h>
 #include <sys/proc.h>
 
