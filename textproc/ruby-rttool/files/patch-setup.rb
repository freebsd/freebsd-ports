--- setup.rb.orig	2009-01-22 02:19:43.000000000 +0900
+++ setup.rb	2014-04-29 06:10:59.000000000 +0900
@@ -169,6 +169,11 @@
     args.each do |i|
       if i == '--no-harm' then
         @no_harm = true
+      elsif /\A--prefix=(.*)\z/ =~ i then
+        path = $1
+        path = File.expand_path(path) unless path[0,1] == '/'
+        @config['prefix'] = path
+        @config.save
       else
         raise InstallError, "install: unknown option #{i}"
       end
@@ -320,7 +325,7 @@
 
   class ConfigTable
 
-    c = ::Config::CONFIG
+    c = ::RbConfig::CONFIG
 
     rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -581,15 +586,15 @@
   #
 
   def install_bin
-    install_all isdir(@config['bin-dir']), 0555
+    install_all isdir(@config['prefix'] + @config['bin-dir']), 0555
   end
 
   def install_rb( dir )
-    install_all isdir(@config['rb-dir'] + '/' + dir), 0644
+    install_all isdir(@config['prefix'] + @config['rb-dir'] + '/' + dir), 0644
   end
 
   def install_dat( dir )
-    install_all isdir(@config['data-dir'] + '/' + dir), 0644
+    install_all isdir(@config['prefix'] + @config['data-dir'] + '/' + dir), 0644
   end
 
   def install_all( dest, mode )
@@ -635,7 +640,7 @@
     end
   end
 
-  DLEXT = ::Config::CONFIG['DLEXT']
+  DLEXT = ::RbConfig::CONFIG['DLEXT']
 
   def find_so( dir )
     fnames = nil
