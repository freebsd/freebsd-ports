--- inc/always.php.orig	2009-02-23 22:35:09.000000000 +0100
+++ inc/always.php	2009-02-23 22:35:48.000000000 +0100
@@ -34,6 +34,7 @@
 
 // Ensure that ../inc is in our included paths as early as possible
 set_include_path( '../inc'. PATH_SEPARATOR. get_include_path());
+set_include_path( '/usr/local/share/awl/inc'. PATH_SEPARATOR. get_include_path());
 
 // Kind of private configuration values
 $c->total_query_time = 0;
