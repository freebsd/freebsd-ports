--- portmanager/pkgtools-to-portmanager.rb.orig	Fri Mar  2 21:28:59 2007
+++ portmanager/pkgtools-to-portmanager.rb	Fri Mar  2 21:30:46 2007
@@ -38,6 +38,8 @@
 
 puts "CATEGORY/PORT|OPTION=|          # do not delete this line!"
 
+init_pkgtools_global
+
 load_config
 
 # held packages
