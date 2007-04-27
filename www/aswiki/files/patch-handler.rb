--- aswiki/handler.rb.dist	Wed Jun 23 10:54:16 2004
+++ aswiki/handler.rb	Fri Apr 27 13:09:17 2007
@@ -138,7 +138,7 @@
       begin
 	c = @repository.load(name)
         orig = c.dup
-	if cgi.value('md5sum')[0] !=  Digest::MD5::new(c.to_s).to_s
+	if cgi.value('md5sum')[0] !=  Digest::MD5::new.update(c.to_s).to_s
 	  bl = body.map{|l| l.sub("\r\n", "\n")}
 	  bol = (cgi.value('ebol')[0] or 1).to_i
 	  eol = (cgi.value('eeol')[0] or c.size).to_i
@@ -164,7 +164,7 @@
       super
       session = CGI::Session.new(cgi ,{'tmpdir' => $DIR_SESSION}) # XXX
       if cgi['md5sum'][0] != 
-	  Digest::MD5::new(@repository.load(session['pname']).to_s).to_s
+	  Digest::MD5::new.update(@repository.load(session['pname']).to_s).to_s
 	raise AsWiki::TimestampMismatch
       end
       cgi.params.each{|key, value| session[key] = value}
@@ -226,7 +226,7 @@
 	c = [true]
       end
       pd = AsWiki::PageData.new(pname)
-      pd.md5sum = Digest::MD5::new(c.to_s).to_s
+      pd.md5sum = Digest::MD5::new.update(c.to_s).to_s
       pd.title  = title
       if body.nil?
 	bol = (cgi.value('ebol')[0] or 1).to_i
