--- psm.c.orig	2012-03-12 02:52:24.120253238 +0600
+++ psm.c	2012-03-12 02:53:17.264235224 +0600
@@ -209,8 +209,7 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <sys/time.h>
-#include <endian.h>
-#include <byteswap.h>
+#include <sys/endian.h>
 #include "mpiexec.h"
 
 #ifdef HAVE_POLL
@@ -221,8 +220,8 @@
 #  define ntohu64(x) (x)
 #  define htonu64(x) (x)
 #elif __BYTE_ORDER == __LITTLE_ENDIAN
-#  define ntohu64(x) __bswap_64(x)
-#  define htonu64(x) __bswap_64(x)
+#  define ntohu64(x) bswap64(x)
+#  define htonu64(x) bswap64(x)
 #endif
 
 #define EPID_INFO_GLOBAL 2
