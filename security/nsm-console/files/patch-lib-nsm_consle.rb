--- lib/nsm_console.rb.orig	2008-01-15 20:23:34.000000000 +0900
+++ lib/nsm_console.rb	2008-01-15 20:24:32.000000000 +0900
@@ -15,7 +15,7 @@
     load_categories($moduledir)
 
     ## Initialize logging
-    logfilename = "logs/nsm-log."
+    logfilename = ENV["HOME"] + "/logs/nsm-log."
     logfilename.concat(Time.now.year.to_s)
     logfilename.concat(Time.now.month.to_s)
     logfilename.concat(Time.now.day.to_s)
@@ -81,4 +81,4 @@
 
     start_shell()
   end
-end
\ No newline at end of file
+end
