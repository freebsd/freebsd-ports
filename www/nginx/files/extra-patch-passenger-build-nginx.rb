--- ../passenger-5.2.1/build/nginx.rb.orig	2018-03-03 21:21:23.833026000 +0100
+++ ../passenger-5.2.1/build/nginx.rb	2018-03-03 21:25:02.268013000 +0100
@@ -39,13 +39,12 @@ auto_generated_sources = %w(
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
@@ -53,7 +52,6 @@ task :_nginx => :nginx
 
 task :nginx_without_native_support => [
   auto_generated_sources,
-  AGENT_TARGET,
   COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
@@ -61,7 +59,6 @@ task :nginx_without_native_support => [
 # it also creates a namespace:clean task to clean up the output_dir
 task :nginx_dynamic_without_native_support => [
   auto_generated_sources,
-  AGENT_TARGET,
   define_libboost_oxt_task("nginx", NGINX_DYNAMIC_OUTPUT_DIR + "libboost_oxt", "-fPIC"),
   COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).
     set_namespace("nginx").set_output_dir(NGINX_DYNAMIC_OUTPUT_DIR + "module_libpassenger_common").define_tasks("-fPIC").
