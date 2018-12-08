--- go/base/Config.php.orig	2018-12-04 16:00:23 UTC
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
@@ -760,21 +760,21 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_zip = '/usr/bin/zip';
+	var $cmd_zip = '/usr/local/bin/zip';
 
 	/**
 	 * Command to unpack ZIP archive
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_unzip = '/usr/bin/unzip';
+	var $cmd_unzip = '/usr/local/bin/unzip';
 
 	/**
 	 * Command to control TAR archives
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_tar = '/bin/tar';
+	var $cmd_tar = '/usr/local/bin/tar';
 
 	/**
 	 * Command to set system passwords. Used by passwd.users.class.inc.
@@ -790,7 +790,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_sudo = '/usr/bin/sudo';
+	var $cmd_sudo = '/usr/local/bin/sudo';
 
 	/**
 	 * Command to convert xml to wbxml
@@ -798,7 +798,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_xml2wbxml = '/usr/bin/xml2wbxml';
+	var $cmd_xml2wbxml = '/usr/local/bin/xml2wbxml';
 
 	/**
 	 * Command to convert wbxml to xml
@@ -806,7 +806,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_wbxml2xml = '/usr/bin/wbxml2xml';
+	var $cmd_wbxml2xml = '/usr/local/bin/wbxml2xml';
 
 	/**
 	 * Command to unpack winmail.dat files
@@ -814,7 +814,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_tnef = '/usr/bin/tnef';
+	var $cmd_tnef = '/usr/local/bin/tnef';
 
 	/**
 	 * Command to execute the php command line interface
@@ -822,7 +822,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_php = 'php';
+	var $cmd_php = '/usr/local/bin/php';
 
 
 	/**
@@ -1350,7 +1350,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	}
 	
 	private function getGlobalConfig() {
-		$globalConfigFile = '/etc/groupoffice/globalconfig.inc.php';
+		$globalConfigFile = '/usr/local/usr/local/etc/groupoffice/globalconfig.inc.php';
 		if (file_exists($globalConfigFile)) {
 			require($globalConfigFile);
 		}
