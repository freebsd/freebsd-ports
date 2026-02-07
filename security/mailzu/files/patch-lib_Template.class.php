--- lib/Template.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/Template.class.php
@@ -30,7 +30,7 @@ class Template {
 	* @param string $title title of page
 	* @param int $depth depth of the current page relative to phpScheduleIt root
 	*/
-	function Template($title = '', $depth = 0) {
+	function __construct($title = '', $depth = 0) {
 		global $conf;
 		
 		$this->title = (!empty($title)) ? $title : $conf['ui']['welcome'];
@@ -57,21 +57,21 @@ class Template {
 	?>
 	<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
 		"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
-	<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?=$languages[$lang][2]?>" lang="<?=$languages[$lang][2]?>">
+	<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php echo$languages[$lang][2]?>" lang="<?php echo$languages[$lang][2]?>">
 	<head>
 	<title>
-	<?=$this->title?>
+	<?php echo $this->title?>
 	</title>
-	<meta http-equiv="Content-Type" content="text/html; charset=<?=$charset?>" />
+	<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset?>" />
 	<link rel="shortcut icon" href="img/favicon.ico" type="image/x-icon" />
-	<script language="JavaScript" type="text/javascript" src="<?=$path?>functions.js"></script>
-	<!--<link href="<?=$path?>css.css" rel="stylesheet" type="text/css" />-->
+	<script language="JavaScript" type="text/javascript" src="<?php echo $path?>functions.js"></script>
+	<!--<link href="<?php echo $path?>css.css" rel="stylesheet" type="text/css" />-->
 	<style type="text/css">
-	@import url(<?=$path?>css.css);
+	@import url(<?php echo $path?>css.css);
 	</style>
 	</head>
 	<body>
-	<?
+	<?php
 	}
 	
 	
@@ -96,31 +96,31 @@ class Template {
 	  <tr>
 		<td class="mainBkgrdClr">
 		  <h4 class="welcomeBack">
-		    <?= 
+		    <?php echo 
 		      translate('Welcome Back', array($_SESSION['sessionName'], 1));
 		      // Notify if the person logged in is admin
 		      echo (Auth::isMailAdmin() ? ' (' . translate('Administrator') . ')' : '');
 		    ?>
 		  </h4>
 		  <!--<p>
-			<? $this->link->doLink($this->dir_path . 'index.php?logout=true', translate('Log Out')) ?>
+			<?php $this->link->doLink($this->dir_path . 'index.php?logout=true', translate('Log Out')) ?>
 			|
-			<? $this->link->doLink($this->dir_path . 'summary.php', translate('My Control Panel')) ?>
+			<?php $this->link->doLink($this->dir_path . 'summary.php', translate('My Control Panel')) ?>
 		  </p>-->
 		</td>
 		<td class="mainBkgrdClr" valign="top">
 		  <div align="right">
 		    <p>
-			<?= translate_date('header', mktime());?>
+			<?php echo translate_date('header', time());?>
 			</p>
 			<!--<p>
-			  <? $this->link->doLink('javascript: help();', translate('Help')) ?>
+			  <?php $this->link->doLink('javascript: help();', translate('Help')) ?>
 			</p>-->
 		  </div>
 		</td>
 	  </tr>
 	</table>
-	<?
+	<?php
 	}
 	
 	
@@ -134,7 +134,7 @@ class Template {
 	<table width="100%" border="0" cellspacing="0" cellpadding="10" style="border: solid #CCCCCC 1px;">
 	  <tr>
 		<td bgcolor="#FAFAFA">
-		  <?
+		  <?php
 	}
 	
 	
@@ -147,7 +147,7 @@ class Template {
 		</td>
 	  </tr>
 	</table>
-	<?
+	<?php
 	}
 	
 	
@@ -160,10 +160,10 @@ class Template {
 	function printHTMLFooter() {
 		global $conf;
 	?>
-	<p align="center"><a href="http://www.mailzu.net"><?=$conf['app']['title']?> v<?=$conf['app']['version']?></a></p>
+	<p align="center"><a href="http://www.mailzu.net"><?php echo $conf['app']['title']?> v<?php echo $conf['app']['version']?></a></p>
 	</body>
 	</html>
-	<?
+	<?php
 	}
 	
 	/**
