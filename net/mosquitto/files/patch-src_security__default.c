--- src/security_default.c.orig	2018-10-11 00:28:56 UTC
+++ src/security_default.c
@@ -18,7 +18,7 @@ Contributors:
 
 #include <stdio.h>
 #include <string.h>
-
+#include <openssl/opensslv.h>
 #include "mosquitto_broker_internal.h"
 #include "memory_mosq.h"
 #include "util_mosq.h"
