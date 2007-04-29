--- plugin/2chbbs.rb.dist	Wed Jan  8 11:01:21 2003
+++ plugin/2chbbs.rb	Sun Apr 29 22:05:37 2007
@@ -24,7 +24,7 @@
       t = Time.now
       time = t.strftime("%Y/%m/%d (#{weekstr[t.wday]}) %R")
       data = "\n#{number}: #{from}: #{name} #{date}: #{time} \n\n" +
-	session['textdata'] + "\n"
+	session['textdata'].to_s + "\n"
       file = @repository.load(pname)
       file[session['begin'].to_i-1, 0 ] = data
       file[session['begin'].to_i] = "#2chbbs #{number}\n"
@@ -40,7 +40,7 @@
       session['number'] = av[1].to_i
       @data = {
 	:_session_id => session.session_id,
-	:md5sum =>  Digest::MD5::new(@repository.load(@name).to_s).to_s,
+	:md5sum =>  Digest::MD5::new.update(@repository.load(@name).to_s).to_s,
 	:msg_2chbbs_from => msg_2chbbs_from,
 	:msg_2chbbs_write => msg_2chbbs_write,
       }
