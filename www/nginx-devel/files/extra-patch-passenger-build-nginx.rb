--- ../passenger-5.0.21/build/nginx.rb.orig	2013-10-27 02:00:00.000000000 +0400
+++ ../passenger-5.0.21/build/nginx.rb	2015-09-26 02:05:27.664684000 +0300
@@ -32,6 +32,7 @@
 desc "Build Nginx support files"
 task :nginx => [
   :nginx_without_native_support,
+  LIBBOOST_OXT,
   NATIVE_SUPPORT_TARGET
 ].compact
 
@@ -40,7 +41,6 @@
 
 task :nginx_without_native_support => [
   auto_generated_sources,
-  AGENT_TARGET,
   COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
