--- src/plugins/node_features/knl_cray/node_features_knl_cray.c.orig	2016-08-24 19:28:33 UTC
+++ src/plugins/node_features/knl_cray/node_features_knl_cray.c
@@ -39,6 +39,12 @@
 #endif
 
 #define _GNU_SOURCE	/* For POLLRDHUP */
+
+#if defined (__FreeBSD__)
+#  define POLLRDHUP POLLHUP
+#  include <signal.h>
+#endif
+
 #include <ctype.h>
 #include <poll.h>
 #include <signal.h>
