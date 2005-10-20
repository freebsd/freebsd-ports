--- html/who.php.orig	Wed Sep 28 19:33:51 2005
+++ html/who.php	Wed Sep 28 19:34:34 2005
@@ -27,7 +27,7 @@
 
 
 $result = shell_exec("w");
-$result2 = shell_exec("free -mo");
+$result2 = shell_exec("pstat -T");
 
 
 DisplayHead(_SERVERSTATS);
