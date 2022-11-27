--- htdocs/login.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/login.php
@@ -22,7 +22,7 @@ if ($pass) {
     $user['password'] = get_request('login_pass');
     $user['password'] = html_entity_decode($user['password'], ENT_QUOTES);
 
-    if ($user['login'] && !strlen($user['password'])) {
+    if ($user['login'] && empty($user['password'])) {
         system_message(array(
             'title' => _('Authenticate to server'),
             'body'  => _('You left the password blank.'),
