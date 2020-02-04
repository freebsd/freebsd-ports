--- go/base/Config.php.orig	2020-01-30 15:07:35.000000000 +0100
+++ go/base/Config.php	2020-02-03 08:46:09.904940000 +0100
@@ -760,7 +760,7 @@
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_zip = '/usr/bin/zip';
+	var $cmd_zip = '/usr/local/bin/zip';
 
 	/**
 	 * Command to unpack ZIP archive
@@ -774,7 +774,7 @@
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_tar = '/bin/tar';
+	var $cmd_tar = '/usr/bin/tar';
 
 	/**
 	 * Command to set system passwords. Used by passwd.users.class.inc.
@@ -783,14 +783,14 @@
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_chpasswd = '/usr/sbin/chpasswd';
+	var $cmd_chpasswd = '/usr/bin/passwd';
 
 	/**
 	 * Command to SUDO
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_sudo = '/usr/bin/sudo';
+	var $cmd_sudo = '/usr/local/bin/sudo';
 
 	/**
 	 * Command to convert xml to wbxml
@@ -798,7 +798,7 @@
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_xml2wbxml = '/usr/bin/xml2wbxml';
+	var $cmd_xml2wbxml = '/usr/local/bin/xml2wbxml';
 
 	/**
 	 * Command to convert wbxml to xml
@@ -806,7 +806,7 @@
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_wbxml2xml = '/usr/bin/wbxml2xml';
+	var $cmd_wbxml2xml = '/usr/local/bin/wbxml2xml';
 
 	/**
 	 * Command to unpack winmail.dat files
@@ -814,7 +814,7 @@
 	 * @var     StringHelper
 	 * @access  public
 	 */
-	var $cmd_tnef = '/usr/bin/tnef';
+	var $cmd_tnef = '/usr/local/bin/tnef';
 
 	/**
 	 * Command to execute the php command line interface
