--- plugin/demo.rb.dist	Wed Jan  8 11:01:21 2003
+++ plugin/demo.rb	Sat Apr 28 13:41:46 2007
@@ -48,7 +48,7 @@
       # session.close
       @data = {
 	:session_id => session.session_id,
-	:md5sum =>  Digest::MD5::new(@repository.load(@name).to_s).to_s,
+	:md5sum =>  Digest::MD5::new.update(@repository.load(@name).to_s).to_s,
 	:msg_list_item => msg_list_item,
 	:msg_list_add => msg_list_add,
       }
