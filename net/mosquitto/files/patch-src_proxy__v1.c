--- src/proxy_v1.c.orig	2026-02-04 22:33:13 UTC
+++ src/proxy_v1.c
@@ -4,6 +4,7 @@
 #else
 #  include <arpa/inet.h>
 #endif
+#include <netinet/in.h>
 #include <stdint.h>
 #include "mosquitto_broker_internal.h"
 #include "mosquitto_internal.h"
