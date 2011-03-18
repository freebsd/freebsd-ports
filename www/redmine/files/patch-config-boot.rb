--- config/boot.rb.orig	2011-03-07 20:44:40.000000000 +0100
+++ config/boot.rb	2011-03-17 21:15:51.000000000 +0100
@@ -1,6 +1,8 @@
 # Don't change this file!
 # Configure your app in config/environment.rb and config/environments/*.rb
 
+require 'thread'
+
 RAILS_ROOT = "#{File.dirname(__FILE__)}/.." unless defined?(RAILS_ROOT)
 
 module Rails
@@ -110,13 +112,13 @@
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
