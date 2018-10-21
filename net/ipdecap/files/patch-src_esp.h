--- src/esp.h.orig	2018-07-19 13:30:02 UTC
+++ src/esp.h
@@ -19,6 +19,8 @@
 */
 
 #include <stdint.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <openssl/evp.h>
 #include "utils.h"
 #pragma once
