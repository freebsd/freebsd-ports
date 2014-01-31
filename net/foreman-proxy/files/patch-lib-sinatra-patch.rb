--- lib/sinatra-patch.rb.orig	2014-01-29 12:16:04.574127338 +0100
+++ lib/sinatra-patch.rb	2014-01-29 12:17:34.113121100 +0100
@@ -17,7 +17,7 @@
 
       puts "Starting Foreman Proxy on #{port} using #{handler_name}" unless handler_name =~/cgi/i
 
-      FileUtils.mkdir_p(File.join(APP_ROOT, 'tmp/pids'))
+    # FileUtils.mkdir_p(File.join(APP_ROOT, 'tmp/pids'))
 
       # Create the PID's parent directory if it doesn't exist yet.
       if SETTINGS.daemon
