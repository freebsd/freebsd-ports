--- lib/proxy/http_download.rb.orig     2021-10-26 14:48:17.000000000 +0200
+++ lib/proxy/http_download.rb  2021-11-24 12:24:12.924526000 +0100
@@ -9,7 +9,7 @@
 
     def initialize(src, dst, read_timeout = nil, connect_timeout = nil, dns_timeout = nil, verify_server_cert = false)
       @dst = dst
-      wget = which("wget")
+      wget = "%%LOCALBASE%%/bin/wget"
       read_timeout ||= DEFAULT_READ_TIMEOUT
       dns_timeout ||= DEFAULT_CONNECT_TIMEOUT
       connect_timeout ||= DEFAULT_DNS_TIMEOUT
