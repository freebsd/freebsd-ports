--- ../passenger-4.0.10/build/nginx.rb.orig	2013-05-28 01:13:38.000000000 +0400
+++ ../passenger-4.0.10/build/nginx.rb	2013-05-28 19:21:20.000000000 +0400
@@ -24,14 +24,11 @@
 desc "Build Nginx support files"
 task :nginx => [
 	:nginx_without_native_support,
+	LIBBOOST_OXT,
 	NATIVE_SUPPORT_TARGET
 ].compact
 
 task :nginx_without_native_support => [
-	AGENT_OUTPUT_DIR + 'PassengerHelperAgent',
-	AGENT_OUTPUT_DIR + 'PassengerWatchdog',
-	AGENT_OUTPUT_DIR + 'PassengerLoggingAgent',
-	AGENT_OUTPUT_DIR + 'SpawnPreparer',
 	COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
