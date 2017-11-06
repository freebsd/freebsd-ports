--- src/layer3.c.orig	2014-09-14 19:16:31 UTC
+++ src/layer3.c
@@ -10,6 +10,13 @@
 #include <string.h>
 #include <assert.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
+#endif
+
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
 
