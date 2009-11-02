--- inc/always.php.orig	2009-10-31 21:11:51.000000000 -0200
+++ inc/always.php	2009-10-31 21:12:29.000000000 -0200
@@ -43,7 +43,7 @@
 $c->readonly_webdav_collections = true;    // WebDAV access is readonly
 
 // Ensure that ../inc is in our included paths as early as possible
-set_include_path( '../inc'. PATH_SEPARATOR. get_include_path());
+set_include_path( '../inc'. PATH_SEPARATOR. '/usr/local/share/awl/inc'. PATH_SEPARATOR. get_include_path());
 
 // Kind of private configuration values
 $c->total_query_time = 0;
