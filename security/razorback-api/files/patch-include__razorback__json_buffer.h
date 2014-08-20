--- ./include/razorback/json_buffer.h.orig	2014-08-20 10:25:03.000000000 -0400
+++ ./include/razorback/json_buffer.h	2014-08-20 10:25:26.000000000 -0400
@@ -9,7 +9,7 @@
 #include <razorback/messages.h>
 #include <razorback/ntlv.h>
 
-#include <json/json.h>
+#include <json-c/json.h>
 
 #ifdef __cplusplus
 extern "C" {
