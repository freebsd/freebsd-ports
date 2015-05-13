--- setup.rb.orig	2009-01-20 10:46:11.000000000 +0900
+++ setup.rb
@@ -785,7 +785,7 @@
     else
       require 'rbconfig'
     end
-    ::Config::CONFIG
+    ::RbConfig::CONFIG
   end
 
   def initialize(ardir_root, config)
