--- src/nd_protocol.c.orig	Wed Nov 20 20:13:36 2002
+++ src/nd_protocol.c	Wed Nov 20 20:14:20 2002
@@ -26,6 +26,7 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #include <netdude/nd.h>
