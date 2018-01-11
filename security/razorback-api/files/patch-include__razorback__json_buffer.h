--- include/razorback/json_buffer.h.orig	2012-01-09 19:40:46 UTC
+++ include/razorback/json_buffer.h
@@ -9,6 +9,7 @@
 #include <razorback/messages.h>
 #include <razorback/ntlv.h>
 
-#include <json/json.h>
+#include <json-c/json.h>
+#include <json-c/bits.h>
 
 #ifdef __cplusplus
 extern "C" {
