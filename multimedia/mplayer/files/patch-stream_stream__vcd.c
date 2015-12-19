--- stream/stream_vcd.c.orig	2015-08-31 08:14:54 UTC
+++ stream/stream_vcd.c
@@ -39,6 +39,7 @@
 #include <errno.h>
 
 #if CONFIG_LIBCDIO
+#include <sys/cdrio.h>
 #include "vcd_read_libcdio.h"
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include "vcd_read_fbsd.h"
