--- config/initializers/sprockets_patch.rb.orig	2024-04-02 08:17:37 UTC
+++ config/initializers/sprockets_patch.rb
@@ -8,7 +8,7 @@
 
 require 'sprockets/utils'
 
-unless Gem::Version.new(Sprockets::VERSION) == Gem::Version.new('3.7.2')
+unless Gem::Version.new(Sprockets::VERSION) == Gem::Version.new('3.7.3')
   raise 'New version of Sprockets detected. This patch can likely be removed.'
 end
 
