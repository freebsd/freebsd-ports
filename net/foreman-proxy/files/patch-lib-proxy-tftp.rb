--- lib/proxy/tftp.rb.orig	2014-06-18 10:54:21.000000000 +0200
+++ lib/proxy/tftp.rb	2014-06-19 15:34:09.887122187 +0200
@@ -107,8 +107,9 @@
       # as the dst might contain another sub directory
       FileUtils.mkdir_p destination.parent
 
-      wget = which("wget")
-      cmd = "#{wget} --timeout=10 --tries=3 --no-check-certificate -nv -c \"#{escape_for_shell(src.to_s)}\" -O \"#{escape_for_shell(destination.to_s)}\""
+#      wget = which("wget")
+#      cmd = "#{wget} --timeout=10 --tries=3 --no-check-certificate -nv -c \"#{escape_for_shell(src.to_s)}\" -O \"#{escape_for_shell(destination.to_s)}\""
+      cmd = "/usr/bin/fetch --timeout=10 --no-verify-hostname --no-verify-peer -a -m -q -o \"#{escape_for_shell(destination.to_s)}\" \"#{escape_for_shell(src.to_s)}\""
       CommandTask.new(cmd)
     end
   end
