--- baculum/protected/Web/Class/WebUserManager.php.orig	2021-09-29 12:58:20 UTC
+++ baculum/protected/Web/Class/WebUserManager.php
@@ -233,7 +233,7 @@ class WebUserManager extends WebModule implements IUse
 			 */
 			// For basic auth take username from web server.
 			if (key_exists('PHP_AUTH_USER' , $_SERVER) && !empty($_SERVER['PHP_AUTH_USER'])) {
-				$username = $_SERVER['PHP_AUTH_USER'];
+				$username = strtolower($_SERVER['PHP_AUTH_USER']);
 				$password = '';
 				$this->getModule('auth')->login($username, $password);
 				$this->Response->redirect('/');
