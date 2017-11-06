--- lib/proxy/http_download.rb.orig	2017-05-08 15:18:42 UTC
+++ lib/proxy/http_download.rb
@@ -6,7 +6,7 @@ module Proxy
 
     def initialize(src, dst)
       @dst = dst
-      wget = which("wget")
+      wget = "%%LOCALBASE%%/bin/wget"
       super("#{wget} --timeout=10 --tries=3 --no-check-certificate -nv -c \"#{escape_for_shell(src.to_s)}\" -O \"#{escape_for_shell(dst.to_s)}\"")
     end
 
