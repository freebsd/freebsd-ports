--- drivers/libdha/irq.c.orig	Sat Apr  5 19:39:46 2003
+++ drivers/libdha/irq.c	Sat Apr  5 19:48:37 2003
@@ -1,6 +1,7 @@
 /* HW IRQ support */
 #include <stdio.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
 #include <sys/mman.h> /* mlock */
 #include <pthread.h>
 #include <errno.h>
