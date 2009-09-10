--- plugins/password/drivers/sql.php.orig	2009-09-10 10:17:30.000000000 +0200
+++ plugins/password/drivers/sql.php	2009-09-10 10:18:05.000000000 +0200
@@ -81,7 +81,7 @@
     $user_info = explode('@', $_SESSION['username']);
     if (count($user_info) >= 2) {
 	$sql = str_replace('%l', $db->quote($user_info[0], 'text'), $sql);
-	$sql = str_replace('%d', $db->quote($user_info[0], 'text'), $sql);
+	$sql = str_replace('%d', $db->quote($user_info[1], 'text'), $sql);
     }
     
     $sql = str_replace('%u', $db->quote($_SESSION['username'],'text'), $sql);
