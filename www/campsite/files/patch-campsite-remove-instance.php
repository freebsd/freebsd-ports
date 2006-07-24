--- implementation/utils/campsite-remove-instance.php.orig	Wed Jul 12 21:49:26 2006
+++ implementation/utils/campsite-remove-instance.php	Thu Jul 13 09:17:11 2006
@@ -10,6 +10,11 @@
 $arg3 = isset($GLOBALS['argv'][3]) ? trim($GLOBALS['argv'][3]) : "";
 $no_backup = $arg3 == '--no_backup';
 
+// include install_conf.php file
+require_once("$etc_dir/install_conf.php");
+require_once($Campsite['BIN_DIR'] . "/cli_script_lib.php");
+
+
 if ($etc_dir == "") {
 	die("Please supply the configuration directory as the first argument.\n");
 }
@@ -21,9 +26,6 @@
 	exit(1);
 }
 
-// include install_conf.php file
-require_once("$etc_dir/install_conf.php");
-require_once($Campsite['BIN_DIR'] . "/cli_script_lib.php");
 
 if (!$no_backup) {
 	// backup instance
