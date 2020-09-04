--- liblttng-ust-fd/lttng-ust-fd.c.orig	2016-11-29 01:46:24 UTC
+++ liblttng-ust-fd/lttng-ust-fd.c
@@ -28,7 +28,7 @@
 #include <helper.h>
 #include "usterr-signal-safe.h"
 
-volatile enum ust_loglevel ust_loglevel;
+extern volatile enum ust_loglevel ust_loglevel;
 
 static int (*__lttng_ust_fd_plibc_close)(int fd);
 
