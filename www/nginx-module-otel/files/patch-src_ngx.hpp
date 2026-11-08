--- src/ngx.hpp.orig	2026-11-08 17:32:16 UTC
+++ src/ngx.hpp
@@ -2,6 +2,7 @@ extern "C" {
 
 extern "C" {
 #include <ngx_config.h>
+#include <nginx.h>
 #include <ngx_core.h>
 #include <ngx_http.h>
 }
