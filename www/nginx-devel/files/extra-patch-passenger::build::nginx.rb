--- ../passenger-3.0.3/build/nginx.rb.orig	2010-12-07 13:57:32.000000000 +0300
+++ ../passenger-3.0.3/build/nginx.rb	2010-12-07 13:58:13.000000000 +0300
@@ -23,10 +23,7 @@
 
 desc "Build Nginx helper agent"
 task :nginx => [
-	AGENT_OUTPUT_DIR + 'nginx/PassengerHelperAgent',
-	AGENT_OUTPUT_DIR + 'PassengerWatchdog',
-	AGENT_OUTPUT_DIR + 'PassengerLoggingAgent',
-	:native_support
+	AGENT_OUTPUT_DIR + 'nginx/PassengerHelperAgent'
 ]
 
 dependencies = [
@@ -51,18 +48,7 @@
 	LIBCOMMON,
 ]
 file AGENT_OUTPUT_DIR + 'nginx/PassengerHelperAgent' => dependencies do
-	output_dir = "#{AGENT_OUTPUT_DIR}nginx"
-	sh "mkdir -p #{output_dir}" if !File.directory?(output_dir)
-	create_executable "#{output_dir}/PassengerHelperAgent",
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
