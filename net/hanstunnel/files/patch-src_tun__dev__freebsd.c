--- src/tun_dev_freebsd.c.orig	2014-02-07 03:36:31 UTC
+++ src/tun_dev_freebsd.c
@@ -31,7 +31,11 @@
 #include <errno.h>
 
 #include <sys/ioctl.h>
+#ifdef __DragonFly__
+#include <net/tun/if_tun.h>
+#else
 #include <net/if_tun.h>
+#endif
 
 /* #include "vtun.h"
 #include "lib.h" */
