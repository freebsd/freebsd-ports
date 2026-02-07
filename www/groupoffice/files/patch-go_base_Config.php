--- go/base/Config.php.orig	2022-02-17 21:30:45.309754000 +0100
+++ go/base/Config.php	2022-02-17 21:38:23.780207000 +0100
@@ -757,21 +757,21 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_zip = '/usr/bin/zip';
+	var $cmd_zip = '/usr/local/bin/zip';
 
 	/**
 	 * Command to unpack ZIP archive
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_unzip = '/usr/bin/unzip';
+	var $cmd_unzip = '/usr/local/bin/unzip';
 
 	/**
 	 * Command to control TAR archives
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_tar = '/bin/tar';
+	var $cmd_tar = '/usr/local/bin/tar';
 
 	/**
 	 * Command to set system passwords. Used by passwd.users.class.inc.
@@ -780,14 +780,14 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_chpasswd = '/usr/sbin/chpasswd';
+	var $cmd_chpasswd = '/usr/local/bin/passwd';
 
 	/**
 	 * Command to SUDO
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_sudo = '/usr/bin/sudo';
+	var $cmd_sudo = '/usr/local/bin/sudo';
 
 	/**
 	 * Command to convert xml to wbxml
@@ -795,7 +795,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_xml2wbxml = '/usr/bin/xml2wbxml';
+	var $cmd_xml2wbxml = '/usr/local/bin/xml2wbxml';
 
 	/**
 	 * Command to convert wbxml to xml
@@ -803,7 +803,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_wbxml2xml = '/usr/bin/wbxml2xml';
+	var $cmd_wbxml2xml = '/usr/local/bin/wbxml2xml';
 
 	/**
 	 * Command to unpack winmail.dat files
@@ -811,7 +811,7 @@ var $billing_clear_payment_method_on_duplicate = true;
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_tnef = '/usr/bin/tnef';
+	var $cmd_tnef = '/usr/local/bin/tnef';
 
 	/**
 	 * Command to execute the php command line interface
