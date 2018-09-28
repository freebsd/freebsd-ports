--- include/nuster/http.h.orig	2018-08-17 06:04:08 UTC
+++ include/nuster/http.h
@@ -14,6 +14,7 @@
 #define _NUSTER_HTTP_H
 
 #include <types/global.h>
+#include <inttypes.h>
 
 #include <proto/stream_interface.h>
 #include <proto/proto_http.h>
