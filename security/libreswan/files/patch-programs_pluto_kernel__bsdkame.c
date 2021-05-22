--- programs/pluto/kernel_bsdkame.c.orig	2021-05-21 21:30:08 UTC
+++ programs/pluto/kernel_bsdkame.c
@@ -24,6 +24,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <sys/queue.h>
+#endif
+
 #include <sys/select.h>
 #include <sys/time.h>
 #include <sys/socket.h>
