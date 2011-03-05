--- libtransmission/torrent.c.orig	2011-02-27 15:39:55.000000000 -0600
+++ libtransmission/torrent.c	2011-02-27 15:40:35.000000000 -0600
@@ -27,6 +27,7 @@
 #include <stdarg.h>
 #include <string.h> /* memcmp */
 #include <stdlib.h> /* qsort */
+#include <signal.h> /* signal() */
 
 #include <event2/util.h> /* evutil_vsnprintf() */
 
