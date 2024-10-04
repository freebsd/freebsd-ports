--- config/initializers/sprockets_patch.rb.orig	2024-09-24 23:32:11 UTC
+++ config/initializers/sprockets_patch.rb
@@ -8,7 +8,7 @@ require 'sprockets/utils'
 
 require 'sprockets/utils'
 
-unless Gem::Version.new(Sprockets::VERSION) == Gem::Version.new('3.7.2')
+unless Gem::Version.new(Sprockets::VERSION) == Gem::Version.new('3.7.5')
   raise 'New version of Sprockets detected. This patch can likely be removed.'
 end
 
