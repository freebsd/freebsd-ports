--- mikutter.rb.orig	2015-05-14 01:40:33 UTC
+++ mikutter.rb
@@ -9,7 +9,7 @@ This software is released under the MIT 
 http://opensource.org/licenses/mit-license.php
 
 =end
-mikutter_directory = File.expand_path(File.dirname(__FILE__))
+mikutter_directory = '%%RUBY_SITELIBDIR%%/mikutter'
 
 unless ENV['DISABLE_BUNDLER_SETUP']
   begin
