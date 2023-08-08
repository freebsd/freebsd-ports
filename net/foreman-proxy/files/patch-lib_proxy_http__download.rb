--- lib/proxy/http_download.rb.orig	2022-09-08 13:50:11 UTC
+++ lib/proxy/http_download.rb
@@ -10,7 +10,7 @@ module Proxy
       logger.warn('Deprecated: HttpDownload read_timeout is deprecated and will be removed in 3.5') if read_timeout
       logger.warn('Deprecated: HttpDownload dns_timeout is deprecated and will be removed in 3.5') if dns_timeout
       connect_timeout ||= DEFAULT_CONNECT_TIMEOUT
-      args = [which('curl')]
+      args = ["%%LOCALBASE%%/bin/curl"]
 
       # no cert verification if set
       args << "--insecure" unless verify_server_cert
