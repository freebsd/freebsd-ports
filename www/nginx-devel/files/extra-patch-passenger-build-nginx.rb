--- ../passenger-4.0.23/build/nginx.rb.orig	2013-10-12 11:05:08.000000000 +0400
+++ ../passenger-4.0.23/build/nginx.rb	2013-10-12 11:06:18.000000000 +0400
@@ -32,16 +32,12 @@
 desc "Build Nginx support files"
 task :nginx => [
 	:nginx_without_native_support,
+        LIBBOOST_OXT,
 	NATIVE_SUPPORT_TARGET
 ].compact
 
 task :nginx_without_native_support => [
 	auto_generated_sources,
-	AGENT_OUTPUT_DIR + 'PassengerHelperAgent',
-	AGENT_OUTPUT_DIR + 'PassengerWatchdog',
-	AGENT_OUTPUT_DIR + 'PassengerLoggingAgent',
-	AGENT_OUTPUT_DIR + 'SpawnPreparer',
-	AGENT_OUTPUT_DIR + 'TempDirToucher',
 	COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
