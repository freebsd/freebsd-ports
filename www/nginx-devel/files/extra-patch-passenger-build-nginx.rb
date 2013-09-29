--- ../passenger-4.0.19/build/nginx.rb.orig	2013-09-07 14:09:13.000000000 +0400
+++ ../passenger-4.0.19/build/nginx.rb	2013-09-07 14:10:31.000000000 +0400
@@ -32,15 +32,12 @@
 desc "Build Nginx support files"
 task :nginx => [
 	:nginx_without_native_support,
+	LIBBOOST_OXT,
 	NATIVE_SUPPORT_TARGET
 ].compact
 
 task :nginx_without_native_support => [
 	auto_generated_sources,
-	AGENT_OUTPUT_DIR + 'PassengerHelperAgent',
-	AGENT_OUTPUT_DIR + 'PassengerWatchdog',
-	AGENT_OUTPUT_DIR + 'PassengerLoggingAgent',
-	AGENT_OUTPUT_DIR + 'SpawnPreparer',
 	COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
