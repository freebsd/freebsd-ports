--- lib/proxy/tftp.rb.orig	2014-01-29 11:01:36.000000000 +0100
+++ lib/proxy/tftp.rb	2014-02-08 12:38:15.087475784 +0100
@@ -105,8 +105,9 @@
       # as the dst might contain another sub directory
       FileUtils.mkdir_p destination.parent
 
-      wget = which("wget")
-      cmd = "#{wget} --timeout=10 --tries=3 --no-check-certificate -nv -c #{src} -O \"#{destination}\""
+      # wget = which("wget")
+      # cmd = "#{wget} --timeout=10 --tries=3 --no-check-certificate -nv -c #{src} -O \"#{destination}\""
+      cmd = "/usr/bin/fetch --timeout=10 --no-verify-hostname --no-verify-peer -a -m -q -o \"#{destination}\" #{src}"
       CommandTask.new(cmd)
     end
   end
