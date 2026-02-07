--- help.php.orig	2007-06-14 19:00:15 UTC
+++ help.php
@@ -1,73 +1,73 @@
-<?php
-/**
-* This is the pop-up help file for the system
-* This function simply prints out an HTML help file for
-* users to reference
-* @author Nick Korbel <lqqkout13@users.sourceforge.net>
-* @version 07-10-04
-* @package phpScheduleIt
-*
-* Copyright (C) 2003 - 2005 phpScheduleIt
-* License: GPL, see LICENSE
-*/
-
-include_once('config/config.php');
-
-global $languages;
-global $lang;
-global $charset;
-
-echo "<?xml version=\"1.0\" encoding=\"$charset\"?" . ">\n";
-?>
-<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
-	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
-<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$languages[$lang][2]?>" lang="<?=$languages[$lang][2]?>">
-<head>
-<title>MailZu <?=translate('Help')?></title>
-<meta http-equiv="Content-Type" content="text/html; charset=<?=$charset?>" />
-<style type="text/css">
-<!--
-li {
-	font-size: 12px;
-	margin-top: 0px;
-	margin-right: 0px;
-	margin-bottom: 0px;
-	margin-left: 0px;
-}
-body {
-	font-family: Verdana, Arial, Helvetica, sans-serif;
-	margin-top: 5px;
-	margin-right: 5px;
-	margin-bottom: 5px;
-	margin-left: 5px;
-	background-color: #F0F0F0;
-}
-p {
-	font-size: 12px;
-	margin-left: 25px;
-	margin-top: 3px;
-}
-h5 {
-	margin-left: 10px;
-}
-a {
-	color: #104E8B;
-}
-a:hover {
-	color: #474747;
-}
--->
-</style>
-</head>
-<body>
-<?
-$help_file = 'lang/' . $languages[$lang][2] . '.help.php';
-if (file_exists($help_file)) {
-	include_once($help_file);
-}
-else {
-	include_once('lang/en.help.php');
-}
-?>
-</body>
+<?php
+/**
+* This is the pop-up help file for the system
+* This function simply prints out an HTML help file for
+* users to reference
+* @author Nick Korbel <lqqkout13@users.sourceforge.net>
+* @version 07-10-04
+* @package phpScheduleIt
+*
+* Copyright (C) 2003 - 2005 phpScheduleIt
+* License: GPL, see LICENSE
+*/
+
+include_once('config/config.php');
+
+global $languages;
+global $lang;
+global $charset;
+
+echo "<?xml version=\"1.0\" encoding=\"$charset\"?" . ">\n";
+?>
+<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
+	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
+<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php echo $languages[$lang][2]?>" lang="<?php echo $languages[$lang][2]?>">
+<head>
+<title>MailZu <?php echo translate('Help')?></title>
+<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset?>" />
+<style type="text/css">
+<!--
+li {
+	font-size: 12px;
+	margin-top: 0px;
+	margin-right: 0px;
+	margin-bottom: 0px;
+	margin-left: 0px;
+}
+body {
+	font-family: Verdana, Arial, Helvetica, sans-serif;
+	margin-top: 5px;
+	margin-right: 5px;
+	margin-bottom: 5px;
+	margin-left: 5px;
+	background-color: #F0F0F0;
+}
+p {
+	font-size: 12px;
+	margin-left: 25px;
+	margin-top: 3px;
+}
+h5 {
+	margin-left: 10px;
+}
+a {
+	color: #104E8B;
+}
+a:hover {
+	color: #474747;
+}
+-->
+</style>
+</head>
+<body>
+<?php
+$help_file = 'lang/' . $languages[$lang][2] . '.help.php';
+if (file_exists($help_file)) {
+	include_once($help_file);
+}
+else {
+	include_once('lang/en.help.php');
+}
+?>
+</body>
 </html>
