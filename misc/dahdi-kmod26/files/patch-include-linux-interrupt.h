--- include/linux/interrupt.h.orig	2015-03-22 01:01:33.625611000 +0600
+++ include/linux/interrupt.h	2015-03-22 01:01:42.854520000 +0600
@@ -1,6 +1,7 @@
 #ifndef _LINUX_INTERRUPT_H_
 #define _LINUX_INTERRUPT_H_
 
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/taskqueue.h>
 #include <linux/kernel.h>
