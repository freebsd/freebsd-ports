--- src/vmod_ip2location.c.orig	2020-07-24 05:30:13 UTC
+++ src/vmod_ip2location.c
@@ -12,6 +12,11 @@
 #include <unistd.h>
 #include <pthread.h>
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#define gcvt(v, d, c) sprintf(c, "%*g", d, v);
+#endif
+
 #include "cache/cache.h"
 
 /* Varnish < 6.2 compat */
