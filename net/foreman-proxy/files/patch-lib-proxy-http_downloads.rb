--- lib/proxy/http_downloads.rb.orig	2014-09-27 09:21:12.321398953 +0200
+++ lib/proxy/http_downloads.rb	2014-09-27 09:21:39.710436545 +0200
@@ -31,8 +31,8 @@
     end
 
     def command(src, dst)
-      wget = which("wget")
+      wget = "%%LOCALBASE%%/bin/wget"
       "#{wget} --timeout=10 --tries=3 --no-check-certificate -nv -c \"#{escape_for_shell(src.to_s)}\" -O \"#{escape_for_shell(dst.to_s)}\""
     end
   end
-end
\ No newline at end of file
+end
