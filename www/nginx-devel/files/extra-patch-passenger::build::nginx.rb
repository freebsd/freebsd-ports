--- ../passenger-3.0.0/build/nginx.rb.orig	2010-10-01 14:22:34.000000000 +0400
+++ ../passenger-3.0.0/build/nginx.rb	2010-12-04 15:27:45.000000000 +0300
@@ -16,10 +16,7 @@
 
 desc "Build Nginx helper agent"
 task :nginx => [
-	'agents/nginx/PassengerHelperAgent',
-	'agents/PassengerWatchdog',
-	'agents/PassengerLoggingAgent',
-	:native_support
+	'agents/nginx/PassengerHelperAgent'
 ]
 
 dependencies = [
@@ -44,17 +41,7 @@
 	LIBCOMMON,
 ]
 file 'agents/nginx/PassengerHelperAgent' => dependencies do
-	sh "mkdir -p agents/nginx" if !File.directory?("agents/nginx")
-	create_executable "agents/nginx/PassengerHelperAgent",
-		'ext/nginx/HelperAgent.cpp',
-		"-Iext -Iext/common " <<
-		"#{PlatformInfo.portability_cflags} " <<
-		"#{EXTRA_CXXFLAGS}  " <<
-		"#{LIBCOMMON} " <<
-		"#{LIBBOOST_OXT} " <<
-		"#{PlatformInfo.portability_ldflags} " <<
-		"#{AGENT_LDFLAGS} " <<
-		"#{EXTRA_LDFLAGS}"
+	true
 end
 
 task :clean => 'nginx:clean'
