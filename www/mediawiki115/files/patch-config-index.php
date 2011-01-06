--- config/index.php.orig	2011-01-06 10:44:27.000000000 +0800
+++ config/index.php	2011-01-06 10:44:59.000000000 +0800
@@ -21,6 +21,7 @@
 
 error_reporting( E_ALL );
 header( "Content-type: text/html; charset=utf-8" );
+header( 'X-Frame-Options: DENY' );
 @ini_set( "display_errors", true );
 
 # In case of errors, let output be clean.
