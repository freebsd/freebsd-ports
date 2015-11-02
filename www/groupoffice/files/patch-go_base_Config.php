--- go/base/Config.php.orig	2015-11-02 07:39:37 UTC
+++ go/base/Config.php
@@ -733,21 +733,21 @@ class Config {
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_zip = '/usr/bin/zip';
+	var $cmd_zip = '%%LOCALBASE%%/bin/zip';
 
 	/**
 	 * Command to unpack ZIP archive
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_unzip = '/usr/bin/unzip';
+	var $cmd_unzip = '%%LOCALBASE%%/bin/unzip';
 
 	/**
 	 * Command to control TAR archives
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_tar = '/bin/tar';
+	var $cmd_tar = '/usr/bin/tar';
 
 	/**
 	 * Command to set system passwords. Used by passwd.users.class.inc.
@@ -756,14 +756,14 @@ class Config {
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_chpasswd = '/usr/sbin/chpasswd';
+	var $cmd_chpasswd = '%%LOCALBASE%%/sbin/chpasswd';
 
 	/**
 	 * Command to SUDO
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_sudo = '/usr/bin/sudo';
+	var $cmd_sudo = '%%LOCALBASE%%/bin/sudo';
 
 	/**
 	 * Command to convert xml to wbxml
@@ -771,7 +771,7 @@ class Config {
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_xml2wbxml = '/usr/bin/xml2wbxml';
+	var $cmd_xml2wbxml = '%%LOCALBASE%%/bin/xml2wbxml';
 
 	/**
 	 * Command to convert wbxml to xml
@@ -779,7 +779,7 @@ class Config {
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_wbxml2xml = '/usr/bin/wbxml2xml';
+	var $cmd_wbxml2xml = '%%LOCALBASE%%/bin/wbxml2xml';
 
 	/**
 	 * Command to unpack winmail.dat files
@@ -787,7 +787,7 @@ class Config {
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_tnef = '/usr/bin/tnef';
+	var $cmd_tnef = '%%LOCALBASE%%/bin/tnef';
 
 	/**
 	 * Command to execute the php command line interface
@@ -795,7 +795,7 @@ class Config {
 	 * @var     string
 	 * @access  public
 	 */
-	var $cmd_php = 'php';
+	var $cmd_php = '%%LOCALBASE%%/bin/php';
 
 
 	/**
