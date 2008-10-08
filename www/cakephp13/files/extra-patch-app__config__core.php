--- ./app/config/core.php.orig	2008-10-02 00:56:53.000000000 -0400
+++ ./app/config/core.php	2008-10-08 08:42:15.000000000 -0400
@@ -56,7 +56,7 @@
  *
  * And uncomment the App.baseUrl below:
  */
-	//Configure::write('App.baseUrl', env('SCRIPT_NAME'));
+	Configure::write('App.baseUrl', env('SCRIPT_NAME'));
 /**
  * Uncomment the define below to use CakePHP admin routes.
  *
