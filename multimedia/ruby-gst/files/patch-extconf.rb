--- extconf.rb.orig	Tue Jun 10 02:38:38 2003
+++ extconf.rb	Thu Jun 26 13:55:11 2003
@@ -20,7 +20,7 @@
 require 'mkmf'
 
 PKG_CONFIG = "pkg-config" 
-GST_PKG    = "gstreamer-libs-0.6"
+GST_PKG    = "gstreamer-0.6"
 
 def create_archive
     ver     = IO.readlines("VERSION").join.strip
