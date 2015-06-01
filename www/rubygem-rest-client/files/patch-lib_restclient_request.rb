--- lib/restclient/request.rb.orig	2015-06-01 12:01:41 UTC
+++ lib/restclient/request.rb
@@ -219,9 +219,9 @@ module RestClient
     def process_result res, & block
       if @raw_response
         # We don't decode raw requests
-        response = RawResponse.new(@tf, res, args)
+        response = RawResponse.new(@tf, res, args, self)
       else
-        response = Response.create(Request.decode(res['content-encoding'], res.body), res, args)
+        response = Response.create(Request.decode(res['content-encoding'], res.body), res, args, self)
       end
 
       if block_given?
