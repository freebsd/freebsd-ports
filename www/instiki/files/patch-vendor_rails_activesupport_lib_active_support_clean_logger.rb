--- vendor/rails/activesupport/lib/active_support/clean_logger.rb.orig	2005-09-21 00:31:08.000000000 -0700
+++ vendor/rails/activesupport/lib/active_support/clean_logger.rb	2005-09-21 00:45:36.000000000 -0700
@@ -10,7 +10,9 @@
   end
 
   private
-    remove_const "Format"
+    if const_defined?(:Format) # Not defined in Ruby 1.8.3
+      remove_const "Format"
+    end
     Format = "%s\n"
     def format_message(severity, timestamp, msg, progname)
       Format % [msg]
--- patch-as_clean_logger_rb ends here ---
