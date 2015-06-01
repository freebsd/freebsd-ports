--- lib/restclient/raw_response.rb.orig	2015-06-01 12:01:41 UTC
+++ lib/restclient/raw_response.rb
@@ -13,12 +13,13 @@ module RestClient
 
     include AbstractResponse
 
-    attr_reader :file
+    attr_reader :file, :request
 
-    def initialize tempfile, net_http_res, args
+    def initialize(tempfile, net_http_res, args, request)
       @net_http_res = net_http_res
       @args = args
       @file = tempfile
+      @request = request
     end
 
     def to_s
