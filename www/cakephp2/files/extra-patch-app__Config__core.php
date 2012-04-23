--- app/Config/core.php.orig	2012-02-20 18:12:19.000000000 +0100
+++ app/Config/core.php	2012-02-20 18:12:37.000000000 +0100
@@ -92,7 +92,7 @@
  *
  * And uncomment the App.baseUrl below:
  */
-	//Configure::write('App.baseUrl', env('SCRIPT_NAME'));
+	Configure::write('App.baseUrl', env('SCRIPT_NAME'));
 
 /**
  * Uncomment the define below to use CakePHP prefix routes.
