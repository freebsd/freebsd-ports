--- extconf.rb.orig	Tue Jun 19 22:34:05 2001
+++ extconf.rb	Sun Mar 16 13:07:23 2003
@@ -2,7 +2,8 @@
 
 require "mkmf"
 
-if !find_library( "ltdl", "lt_dlinit", "/usr/lib", "/usr/local/lib" )
+if /freebsd/ !~ RUBY_PLATFORM &&
+  !find_library( "ltdl", "lt_dlinit", "/usr/lib", "/usr/local/lib" )
 
   puts
   puts( "Oops, the Libltdl library from the libtool package, which is used by mcrypt," )
