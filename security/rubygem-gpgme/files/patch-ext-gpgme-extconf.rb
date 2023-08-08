--- ext/gpgme/extconf.rb.orig	2022-10-13 10:24:31 UTC
+++ ext/gpgme/extconf.rb
@@ -60,7 +60,6 @@ follows:
 EOS
 
   require 'rubygems'
-  require 'mini_portile2'
 
   libgpg_error_recipe = MiniPortile.new('libgpg-error', '1.46').tap do |recipe|
     recipe.target = File.join(ROOT, "ports")
