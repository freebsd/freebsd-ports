--- install.rb.orig	2016-02-03 17:53:10.253692000 +0000
+++ install.rb	2016-02-03 17:53:44.504039000 +0000
@@ -45,7 +45,7 @@
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -692,7 +692,7 @@
         "no extention exists: Have you done 'ruby #{$0} setup' ?"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _allext( dir )
     Dir.open(dir) {|d|
