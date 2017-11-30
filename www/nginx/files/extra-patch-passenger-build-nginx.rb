--- ../passenger-5.1.12/build/nginx.rb.orig	2013-10-26 18:00:00.000000000 -0400
+++ ../passenger-5.1.12/build/nginx.rb	2016-05-09 18:21:22.426777000 -0400
@@ -33,13 +33,12 @@
 desc "Build Nginx support files"
 task :nginx => [
   :nginx_without_native_support,
-  NATIVE_SUPPORT_TARGET
+  LIBBOOST_OXT,
 ].compact
 
 desc "Build Nginx support files, including objects suitable for dynamic linking against Nginx"
 task 'nginx:as_dynamic_module' => [
   :nginx_dynamic_without_native_support,
-  NATIVE_SUPPORT_TARGET
 ].compact
 
 # Workaround for https://github.com/jimweirich/rake/issues/274
@@ -47,7 +46,6 @@
 
 task :nginx_without_native_support => [
   auto_generated_sources,
-  AGENT_TARGET,
   COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
@@ -55,7 +53,6 @@
 # it also creates a namespace:clean task to clean up the output_dir
 task :nginx_dynamic_without_native_support => [
   auto_generated_sources,
-  AGENT_TARGET,
   define_libboost_oxt_task("nginx", NGINX_DYNAMIC_OUTPUT_DIR + "libboost_oxt", "-fPIC"),
   COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).
     set_namespace("nginx").set_output_dir(NGINX_DYNAMIC_OUTPUT_DIR + "module_libpassenger_common").define_tasks("-fPIC").
