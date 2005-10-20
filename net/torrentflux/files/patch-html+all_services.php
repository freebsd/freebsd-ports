--- html/all_services.php.orig	Wed Sep 28 19:33:42 2005
+++ html/all_services.php	Wed Sep 28 19:34:20 2005
@@ -28,7 +28,7 @@
 $result = shell_exec("df -h ".$cfg["path"]);
 $result2 = shell_exec("du -sh ".$cfg["path"]."*");
 $result4 = shell_exec("w");
-$result5 = shell_exec("free -mo");
+$result5 = shell_exec("pstat -T");
 
 DisplayHead(_ALL);
 echo "<table width=\"740\" border=0 cellpadding=0 cellspacing=0><tr><td>";
