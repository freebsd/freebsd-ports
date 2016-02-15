--- src/core/ngx_module.h.orig	2016-02-10 19:26:57.903123000 -0500
+++ src/core/ngx_module.h	2016-02-10 19:27:40.978113000 -0500
@@ -253,7 +253,7 @@
     ngx_uint_t            spare1;
 
     ngx_uint_t            version;
-    char                 *signature;
+    const char           *signature;
 
     void                 *ctx;
     ngx_command_t        *commands;
