--- src/tls.h.orig	2018-12-06 04:14:58 UTC
+++ src/tls.h
@@ -28,6 +28,6 @@
 
 #include "protocol.h"
 
-const struct Protocol *const tls_protocol;
+extern const struct Protocol *const tls_protocol;
 
 #endif
