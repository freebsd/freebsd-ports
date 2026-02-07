--- templates/auth.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/auth.template.php
@@ -27,19 +27,19 @@ function printLoginForm($msg = '', $resume = '') {
 	if (!empty($msg)) 
 		CmnFns::do_error_box($msg, '', false);
 ?>
-<form name="login" method="post" action="<?=$_SERVER['PHP_SELF']?>">
+<form name="login" method="post" action="<?php echo $_SERVER['PHP_SELF']?>">
 <table width="350px" border="0" cellspacing="0" cellpadding="1" align="center">
 <tr>
   <td bgcolor="#CCCCCC">
 	<table width="100%" border="0" cellspacing="0" cellpadding="3">
 	  <tr bgcolor="#EDEDED">
 		<td colspan="2" style="border-bottom: solid 1px #CCCCCC;">
-		  <h5 align="center"><?=translate('Please Log In')?></h5>
+		  <h5 align="center"><?php echo translate('Please Log In')?></h5>
 		</td>
 	  </tr>
 	  <tr bgcolor="#FFFFFF">
 		<td width="150">
-		  <p><b><?=translate('Login')?></b></p>
+		  <p><b><?php echo translate('Login')?></b></p>
 		</td>
 		<td>
 		  <input type="text" name="email" class="textbox" />
@@ -47,7 +47,7 @@ function printLoginForm($msg = '', $resume = '') {
 	  </tr>
 	  <tr bgcolor="#FFFFFF">
 		<td>
-		  <p><b><?=translate('Password')?></b></p>
+		  <p><b><?php echo translate('Password')?></b></p>
 		</td>
 		<td>
 		  <input type="password" name="password" class="textbox" />
@@ -56,26 +56,26 @@ function printLoginForm($msg = '', $resume = '') {
 	  <?php if ($conf['auth']['serverType'] === 'exchange') { ?>
 	  <tr bgcolor="#FFFFFF">
 		<td>
-		  <p><b><?=translate('Domain')?></b></p>
+		  <p><b><?php echo translate('Domain')?></b></p>
 		</td>
 		<td>
-		  <input type="text" name="domain" class="textbox" value="<?=$conf['auth']['exch_domain']?>"/>
+		  <input type="text" name="domain" class="textbox" value="<?php echo $conf['auth']['exch_domain']?>"/>
 		</td>
 	  </tr>
 	  <?php }
 	  if ($conf['app']['selectLanguage']) { ?>
 	  <tr bgcolor="#FFFFFF">
 		<td>
-		  <p><b><?=translate('Language')?></b></p>
+		  <p><b><?php echo translate('Language')?></b></p>
 		</td>
 		<td>
-		<?CmnFns::print_language_pulldown()?>
+		<?php CmnFns::print_language_pulldown()?>
 		</td>
 	  </tr>
 	  <?php } ?>
 	  <tr bgcolor="#FFFFFF">
 		<td>
-		  <p><b><?=translate('Keep me logged in')?></b></p>
+		  <p><b><?php echo translate('Keep me logged in')?></b></p>
 		</td>
 		<td>
 		  <input type="checkbox" name="setCookie" value="true" />
@@ -84,8 +84,8 @@ function printLoginForm($msg = '', $resume = '') {
 	  <tr bgcolor="#FAFAFA">
 		<td colspan="2" style="border-top: solid 1px #CCCCCC;">
 		   <p align="center">
-			<input type="submit" name="login" value="<?=translate('Log In')?>" class="button" />
-			<input type="hidden" name="resume" value="<?=$resume?>" />
+			<input type="submit" name="login" value="<?php echo translate('Log In')?>" class="button" />
+			<input type="hidden" name="resume" value="<?php echo $resume?>" />
 		  </p>
 		</td>
 	  </tr>
@@ -94,9 +94,9 @@ function printLoginForm($msg = '', $resume = '') {
 </tr>
 </table>
 <p align="center">
-<? $link->doLink('javascript: help();', translate('Help'), '', '', translate('Get online help')) ?>
+<?php $link->doLink('javascript: help();', translate('Help'), '', '', translate('Get online help')) ?>
 </p>
 </form>
-<?
+<?php
 }
 ?>
