--- bacula-web/index.php.orig	Thu Oct  6 10:45:48 2005
+++ bacula-web/index.php	Sat Apr 29 16:35:59 2006
@@ -26,9 +26,9 @@
 //$smarty->compile_check = true;
 //$smarty->debugging = true;
 $smarty->template_dir = "./templates";
-$smarty->compile_dir = "./templates_c";
-$smarty->config_dir     = "./configs";
-$smarty->config_load("bacula.conf");                                                                                    // Load config file
+$smarty->compile_dir = "/var/bacula-web/templates_c";
+$smarty->config_dir     = "/usr/local/etc";
+$smarty->config_load("bacula-web.conf");                                                                                    // Load config file
 $mode = $smarty->get_config_vars("mode");                                                                               // Lite o Extend?

 require("lang.php");
@@ -75,8 +75,11 @@

 $client->free();
 $totalfiles->free();
-$last24bytes->free();
-
+if ( $dbSql->driver == "mysql" ) {
+  $last24bytes->free();
+} else {
+#  $last24bytes->freeResult();
+}

 // report_select.tpl & last_run_report.tpl
 $res = $dbSql->link->query("select Name from Job group by Name");
