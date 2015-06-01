--- lib/restclient/response.rb.orig	2015-06-01 12:01:41 UTC
+++ lib/restclient/response.rb
@@ -6,17 +6,14 @@ module RestClient
 
     include AbstractResponse
 
-    attr_accessor :args, :body, :net_http_res
-
     def body
       self
     end
 
-    def Response.create body, net_http_res, args
+    def self.create body, net_http_res, args, request
       result = body || ''
       result.extend Response
-      result.net_http_res = net_http_res
-      result.args = args
+      result.response_set_vars(net_http_res, args, request)
       result
     end
 
