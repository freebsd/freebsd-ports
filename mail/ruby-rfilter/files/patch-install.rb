--- install.rb.orig	2016-04-04 21:38:57 UTC
+++ install.rb
@@ -45,7 +45,7 @@ end
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -692,7 +692,7 @@ class Installer
         "no extention exists: Have you done 'ruby #{$0} setup' ?"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _allext( dir )
     Dir.open(dir) {|d|
