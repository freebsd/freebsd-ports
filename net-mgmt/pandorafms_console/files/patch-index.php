--- index.php
+++ index.php
@@ -45,7 +45,7 @@ if ($develop_bypass != 1) {
 	if (isset($_POST["rename_file"])){
 		$rename_file_install = (bool)$_POST["rename_file"];
 		if ($rename_file_install) {
-			$salida_rename = rename("/var/www/html/pandora_console/install.php", "/var/www/html/pandora_console/install_old.php");
+			$salida_rename = rename("install.php", "install_old.php");
 		}
 	}
 
