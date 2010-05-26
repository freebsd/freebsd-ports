--- vendor/rails/actionpack/lib/action_controller.rb.orig	2010-01-09 12:56:23.000000000 +0100
+++ vendor/rails/actionpack/lib/action_controller.rb	2010-05-26 11:17:16.000000000 +0200
@@ -31,7 +31,7 @@
   end
 end
 
-gem 'rack', '~> 1.0.1'
+gem 'rack', '>= 1.0.1'
 require 'rack'
 require 'action_controller/cgi_ext'
 
