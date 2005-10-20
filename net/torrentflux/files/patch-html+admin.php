--- html/admin.php.orig	Fri Sep 30 19:40:51 2005
+++ html/admin.php	Sun Oct  2 01:48:40 2005
@@ -212,6 +212,9 @@
 		case "mysql":
 			$sCommand = "mysqldump -h ".$cfg["db_host"]." -u ".$cfg["db_user"]." --password=".$cfg["db_pass"]." --all -f ".$cfg["db_name"]." > ".$sql_file;
 			break;
+		case "sqlite":
+			$sCommand = "sqlite ".$cfg["db_host"]." .dump > ".$sql_file;
+			break;
 		default:
 			// no support for backup-on-demand.
 			$sCommand = "";
