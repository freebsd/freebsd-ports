--- http-access.rb.orig	Fri Jun  9 21:09:28 2000
+++ http-access.rb	Sat Mar 31 20:31:39 2001
@@ -28,7 +28,6 @@
 
 #----------------------------------------------------------------------
 class HTTPAccess
-  include URIModule
 
   HTTP_Port = 80
   attr_reader :http_version, :code, :message, :headers
@@ -109,7 +108,12 @@
   end
 
   def request_post(path, query, header=nil, maxbytes=nil, &block)
-    queryStr = escape_query(query)
+    queryStr = case query
+      when Array
+        escape_query(query)
+      else
+	query.to_s
+      end
     request('POST', path, header, queryStr)
     if block
       get_response
