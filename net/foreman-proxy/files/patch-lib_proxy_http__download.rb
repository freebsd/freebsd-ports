--- lib/proxy/http_download.rb.orig	2018-12-06 13:30:25.000000000 +0100
+++ lib/proxy/http_download.rb	2019-02-11 22:33:58.455890000 +0100
@@ -9,7 +9,7 @@
 
     def initialize(src, dst, read_timeout = nil, connect_timeout = nil, dns_timeout = nil)
       @dst = dst
-      wget = which("wget")
+      wget = "%%LOCALBASE%%/bin/wget"
       read_timeout ||= DEFAULT_READ_TIMEOUT
       dns_timeout ||= DEFAULT_CONNECT_TIMEOUT
       connect_timeout ||= DEFAULT_DNS_TIMEOUT
