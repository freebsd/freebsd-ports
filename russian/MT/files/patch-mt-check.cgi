--- mt-check.cgi.orig	2013-12-02 02:40:30.000000000 +0900
+++ mt-check.cgi	2014-04-16 15:19:09.000000000 +0900
@@ -97,9 +97,9 @@
 my $view    = $cgi->param("view");
 my $version = $cgi->param("version");
 my $sess_id = $cgi->param('session_id');
-$version ||= '5.2.9-ru';
+$version ||= '5.2.10-ru';
 if ( $version eq '__PRODUCT_VERSION' . '_ID__' ) {
-    $version = '5.2.9';
+    $version = '5.2.10';
 }
 
 my ( $mt, $LH );
