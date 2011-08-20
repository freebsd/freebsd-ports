--- lib/rabbit/logger/base.rb.orig	2011-04-29 16:19:39.000000000 +0900
+++ lib/rabbit/logger/base.rb	2011-08-20 18:53:13.000000000 +0900
@@ -65,7 +65,7 @@
         log(INFO, message_or_error, &block)
       end
       
-      def warn(message_or_error=nil, &block)
+      def warning(message_or_error=nil, &block)
         log(WARNING, message_or_error, &block)
       end
 
