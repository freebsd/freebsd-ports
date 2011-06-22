--- src/xine-engine/post.h.orig	2010-06-03 15:54:12.000000000 +0200
+++ src/xine-engine/post.h	2010-06-03 15:59:20.000000000 +0200
@@ -377,7 +377,7 @@ static xine_post_api_parameter_t temp_p[
 
 #define PARAM_ITEM( param_type, var, enumv, min, max, readonly, descr ) \
 { param_type, #var, sizeof(temp_s.var), \
-  (char*)&temp_s.var-(char*)&temp_s, enumv, min, max, readonly, descr },
+  offsetof(typeof(temp_s), var), enumv, min, max, readonly, descr },
 
 #define END_PARAM_DESCR( name ) \
   { POST_PARAM_TYPE_LAST, NULL, 0, 0, NULL, 0, 0, 1, NULL } \
