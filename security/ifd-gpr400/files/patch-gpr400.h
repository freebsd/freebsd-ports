--- gpr400.h.orig	Thu Aug  9 03:14:27 2001
+++ gpr400.h	Sun Sep  8 18:10:47 2002
@@ -18,7 +18,7 @@
 #ifndef gpr400_h
 #define gpr400_h
 
-#include <linux/ioctl.h>
+#include <sys/ioccom.h>
 
 /*
  * Structure used to fetch reader status information
