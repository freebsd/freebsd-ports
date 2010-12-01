--- ../passenger-3.0.0/build/nginx.rb.orig	2010-10-01 14:22:34.000000000 +0400
+++ ../passenger-3.0.0/build/nginx.rb	2010-12-01 11:52:32.000000000 +0300
@@ -17,8 +17,6 @@
 desc "Build Nginx helper agent"
 task :nginx => [
 	'agents/nginx/PassengerHelperAgent',
-	'agents/PassengerWatchdog',
-	'agents/PassengerLoggingAgent',
 	:native_support
 ]
 
@@ -44,17 +42,7 @@
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
