--- ext/gpgme/extconf.rb.orig	2025-06-24 09:21:26 UTC
+++ ext/gpgme/extconf.rb
@@ -63,7 +63,6 @@ EOS
 EOS
 
   require 'rubygems'
-  require 'mini_portile2'
 
   libgpg_error_recipe = MiniPortile.new('libgpg-error', '1.47').tap do |recipe|
     recipe.target = File.join(ROOT, "ports")
