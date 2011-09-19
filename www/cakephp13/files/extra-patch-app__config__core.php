--- ./app/config/core.php.orig	2011-07-26 13:46:14.000000000 -0400
+++ ./app/config/core.php	2011-09-16 14:24:26.000000000 -0400
@@ -66,7 +66,7 @@
  *
  * And uncomment the App.baseUrl below:
  */
-	//Configure::write('App.baseUrl', env('SCRIPT_NAME'));
+	Configure::write('App.baseUrl', env('SCRIPT_NAME'));
 
 /**
  * Uncomment the define below to use CakePHP prefix routes.
