--- go/base/Config.php.orig	2016-10-07 11:58:58 UTC
+++ go/base/Config.php
@@ -22,7 +22,7 @@
  * This class holds the main configuration options of Group-Office
  * Don't modify this file. The values defined here are just default values.
  * They are overwritten by the configuration options in /config.php or
- * /etc/groupoffice/{HOSTNAME}/config.php
+ * /usr/local/usr/local/etc/groupoffice/{HOSTNAME}/config.php
  *
  * To edit these options use install.php.
  *
@@ -786,7 +786,7 @@ class Config {
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_xml2wbxml = '/usr/bin/xml2wbxml';
+	var $cmd_xml2wbxml = '/usr/local/bin/xml2wbxml';
 
 	/**
 	 * Command to convert wbxml to xml
@@ -794,7 +794,7 @@ class Config {
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_wbxml2xml = '/usr/bin/wbxml2xml';
+	var $cmd_wbxml2xml = '/usr/local/bin/wbxml2xml';
 
 	/**
 	 * Command to unpack winmail.dat files
@@ -802,7 +802,7 @@ class Config {
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_tnef = '/usr/bin/tnef';
+	var $cmd_tnef = '/usr/local/bin/tnef';
 
 	/**
 	 * Command to execute the php command line interface
@@ -810,7 +810,7 @@ class Config {
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_php = 'php';
+	var $cmd_php = '/usr/local/bin/php';
 
 
 	/**
@@ -1290,8 +1290,8 @@ class Config {
 		$this->root_path = str_replace('\\','/',dirname(dirname(dirname(__FILE__)))).'/';
 
 		//suppress error for open_basedir warnings etc
-		if(@file_exists('/etc/groupoffice/globalconfig.inc.php')) {
-			require('/etc/groupoffice/globalconfig.inc.php');
+		if(@file_exists('/usr/local/usr/local/etc/groupoffice/globalconfig.inc.php')) {
+			require('/usr/local/usr/local/etc/groupoffice/globalconfig.inc.php');
 		}
 
 		$config_file = $this->get_config_file();
@@ -1615,13 +1615,13 @@ class Config {
 				}
 			}*/
 			if(!empty($_SERVER['SERVER_NAME'])){
-				$config_file = '/etc/groupoffice/'.$_SERVER['SERVER_NAME'].'/config.php';
+				$config_file = '/usr/local/usr/local/etc/groupoffice/'.$_SERVER['SERVER_NAME'].'/config.php';
 				if(@file_exists($config_file)) {
 					$_SESSION['GO_SESSION']['config_file']=$config_file;
 					return $config_file;
 				}
 			}
-			$config_file = '/etc/groupoffice/config.php';
+			$config_file = '/usr/local/usr/local/etc/groupoffice/config.php';
 			if(@file_exists($config_file)) {
 				$_SESSION['GO_SESSION']['config_file']=$config_file;
 				return $config_file;
