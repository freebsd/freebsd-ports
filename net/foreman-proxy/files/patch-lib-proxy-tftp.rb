--- lib/proxy/tftp.rb.orig	2014-01-29 00:26:35.629061321 +0100
+++ lib/proxy/tftp.rb	2014-01-29 00:28:05.669054835 +0100
@@ -104,7 +104,7 @@
       # as the dst might contain another sub directory
       FileUtils.mkdir_p destination.parent
 
-      cmd = "wget --timeout=10 --tries=3 --no-check-certificate -nv -c #{src} -O \"#{destination}\""
+      cmd = "/usr/bin/fetch --timeout=10 --no-verify-hostname --no-verify-peer -a -m -q -o \"#{destination}\" #{src}"
       Proxy::Util::CommandTask.new(cmd)
     end
   end
