--- lib/tdiary/request.rb.orig	2017-06-29 08:19:50 UTC
+++ lib/tdiary/request.rb
@@ -1,5 +1,6 @@
 # stolen from okkez http://github.com/hiki/hiki/blob/rack/hiki/request.rb
 module TDiary
+	require 'rack'
 	class Request < ::Rack::Request
 		include RequestExtension
 
