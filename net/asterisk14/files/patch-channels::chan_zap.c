
$FreeBSD$

--- channels/chan_zap.c
+++ channels/chan_zap.c
@@ -42,7 +42,9 @@
 #include <sys/signal.h>
 #include <errno.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <unistd.h>
 #include <sys/ioctl.h>
 #ifdef __linux__
