--- bacula-web/report.php.orig	Thu Oct  6 10:45:48 2005
+++ bacula-web/report.php	Sat Apr 29 16:36:01 2006
@@ -25,9 +25,9 @@
 //$smarty->debugging = true;

 $smarty->template_dir   = "./templates";
-$smarty->compile_dir    = "./templates_c";
-$smarty->config_dir     = "./configs";
-$smarty->config_load("bacula.conf");
+$smarty->compile_dir    = "/var/bacula-web/templates_c";
+$smarty->config_dir     = "/usr/local/etc";
+$smarty->config_load("bacula-web.conf");
 require("lang.php");

 $dbSql = new Bweb();
