--- lib/tdiary/request.rb.orig	2016-01-16 10:16:46 UTC
+++ lib/tdiary/request.rb
@@ -1,6 +1,7 @@
 # -*- coding: utf-8 -*-
 # stolen from okkez http://github.com/hiki/hiki/blob/rack/hiki/request.rb
 module TDiary
+	require 'rack'
 	class Request < ::Rack::Request
 		include RequestExtension
 
