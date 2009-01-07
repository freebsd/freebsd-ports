--- lib/constant.php.orig Fri Jun  8 15:15:54 2007
+++ lib/constant.php      Fri Jun  8 15:16:10 2007
@@ -24,7 +24,7 @@
 */
 
 /* absolute path to the configuration file */
-$config_file = '/etc/hastymail.conf';
+$config_file = '%%PREFIX%%/etc/hastymail.conf';
 
 /* hastymail version */
 $version = '1.5';
