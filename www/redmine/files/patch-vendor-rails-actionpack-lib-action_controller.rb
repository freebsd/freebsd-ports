--- vendor/rails/actionpack/lib/action_controller.rb.orig	2011-05-30 18:53:34.000000000 +0200
+++ vendor/rails/actionpack/lib/action_controller.rb	2011-05-31 11:50:23.000000000 +0200
@@ -31,7 +31,7 @@
   end
 end
 
-gem 'rack', '~> 1.1.0'
+gem 'rack', '>= 1.1.0'
 require 'rack'
 require 'action_controller/cgi_ext'
 
