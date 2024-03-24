--- deps/quicly/lib/quicly.c.orig	2023-11-11 22:44:34 UTC
+++ deps/quicly/lib/quicly.c
@@ -21,6 +21,7 @@
  */
 #include <assert.h>
 #include <inttypes.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <pthread.h>
