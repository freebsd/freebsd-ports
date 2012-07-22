--- lib/quickml/config.rb.orig	2012-06-21 17:13:32.000000000 +0900
+++ lib/quickml/config.rb	2012-06-21 17:13:46.000000000 +0900
@@ -62,7 +62,7 @@
       @confirm_ml_creation = (config[:confirm_ml_creation] or false)
 
       instance_variables.each {|name|
-	self.class.class_eval { attr_reader name.delete('@') }
+	self.class.class_eval { attr_reader name.to_s.delete('@') }
       }
     end
 
