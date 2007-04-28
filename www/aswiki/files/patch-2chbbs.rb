--- plugin/2chbbs.rb.dist	Wed Jan  8 11:01:21 2003
+++ plugin/2chbbs.rb	Sat Apr 28 13:41:24 2007
@@ -40,7 +40,7 @@
       session['number'] = av[1].to_i
       @data = {
 	:_session_id => session.session_id,
-	:md5sum =>  Digest::MD5::new(@repository.load(@name).to_s).to_s,
+	:md5sum =>  Digest::MD5::new.update(@repository.load(@name).to_s).to_s,
 	:msg_2chbbs_from => msg_2chbbs_from,
 	:msg_2chbbs_write => msg_2chbbs_write,
       }
