--- ./libgrive/src/protocol/Json.cc.orig	2014-08-20 11:44:51.000000000 -0400
+++ ./libgrive/src/protocol/Json.cc	2014-08-20 11:45:03.000000000 -0400
@@ -29,8 +29,8 @@
 	#pragma warning(push)
 	#pragma warning(disable: 4005)
 #endif
-#include <json/json_tokener.h>
-#include <json/linkhash.h>
+#include <json-c/json_tokener.h>
+#include <json-c/linkhash.h>
 #ifdef _MSC_VER
 	#pragma warning(pop)
 #endif
