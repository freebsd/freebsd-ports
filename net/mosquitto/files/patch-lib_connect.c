--- lib/connect.c.orig	2026-02-04 22:33:13 UTC
+++ lib/connect.c
@@ -26,6 +26,7 @@ Contributors:
 #else
 #  include <arpa/inet.h>
 #endif
+#include <netinet/in.h>
 
 #include "callbacks.h"
 #include "http_client.h"
