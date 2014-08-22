--- ../passenger-4.0.49/build/nginx.rb.orig	2013-10-27 02:00:00.000000000 +0400
+++ ../passenger-4.0.49/build/nginx.rb	2014-06-02 05:55:12.000000000 +0400
@@ -32,6 +32,7 @@
 desc "Build Nginx support files"
 task :nginx => [
 	:nginx_without_native_support,
+	LIBBOOST_OXT,
 	NATIVE_SUPPORT_TARGET
 ].compact
 
@@ -40,11 +41,6 @@
 
 task :nginx_without_native_support => [
 	auto_generated_sources,
-	AGENT_OUTPUT_DIR + 'PassengerHelperAgent',
-	AGENT_OUTPUT_DIR + 'PassengerWatchdog',
-	AGENT_OUTPUT_DIR + 'PassengerLoggingAgent',
-	AGENT_OUTPUT_DIR + 'SpawnPreparer',
-	AGENT_OUTPUT_DIR + 'TempDirToucher',
 	COMMON_LIBRARY.only(*NGINX_LIBS_SELECTOR).link_objects
 ].flatten
 
