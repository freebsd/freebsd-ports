--- config/boot.rb.orig	2010-12-23 11:22:21.000000000 +0100
+++ config/boot.rb	2010-12-23 14:14:20.000000000 +0100
@@ -110,13 +110,13 @@
 # Loads i18n 0.4.2 before Rails loads any more recent gem
 # 0.5.0 is not compatible with the old interpolation syntax
 # Plugins will have to migrate to the new syntax for 1.2.0
-require 'rubygems'
-begin
-  gem 'i18n', '0.4.2'
-rescue Gem::LoadError => load_error
-  $stderr.puts %(Missing the i18n 0.4.2 gem. Please `gem install -v=0.4.2 i18n`)
-  exit 1
-end
+#require 'rubygems'
+#begin
+#  gem 'i18n', '0.4.2'
+#rescue Gem::LoadError => load_error
+#  $stderr.puts %(Missing the i18n 0.4.2 gem. Please `gem install -v=0.4.2 i18n`)
+#  exit 1
+#end
 
 # All that for this:
 Rails.boot!
