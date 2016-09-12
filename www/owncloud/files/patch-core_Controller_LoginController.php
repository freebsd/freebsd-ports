--- core/Controller/LoginController.php.orig	2016-09-12 05:18:21 UTC
+++ core/Controller/LoginController.php
@@ -185,7 +185,7 @@ class LoginController extends Controller
 		}
 		if ($loginResult === false) {
 			$this->session->set('loginMessages', [
-				['invalidpassword']
+				['invalidpassword'], []
 			]);
 			// Read current user and append if possible - we need to return the unmodified user otherwise we will leak the login name
 			$args = !is_null($user) ? ['user' => $originalUser] : [];
