--- templates/sendmail.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/sendmail.template.php
@@ -19,7 +19,7 @@ function printsendmail(){
 		<table width="100%" border="0" cellspacing="1" cellpadding="0">
                                 <tr>
                                 <td class="tableTitle">
-				<? 
+				<?php 
 				$adminEmail = $conf['app']['adminEmail'];
 				$emailList = '';
 				if ( is_array($adminEmail) ) {
@@ -35,7 +35,7 @@ function printsendmail(){
 				</td>
 				<td class="tableTitle">
                                 <div align="right">
-                                        <? $link->doLink('javascript: help(\'msg_index\');', '?', '', 'color: #FFFFFF;',
+                                        <?php $link->doLink('javascript: help(\'msg_index\');', '?', '', 'color: #FFFFFF;',
                                                 translate('Help') . ' - ' . translate('Email Administrator')) ?>
                                 </div>
                                 </td>
@@ -45,11 +45,11 @@ function printsendmail(){
 		<table class="stdFont" width="100%" height="100%" border="0" cellspacing="1" cellpadding="0">
 
 			<tr class="cellColor" align="left">
-			<form name="sendmail_to_admin_form" action="<? echo $_SERVER['PHP_SELF']; ?>" method="POST">
+			<form name="sendmail_to_admin_form" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
 			<td><br />
-			&nbsp;&nbsp;<? echo translate('Subject') . ": " ;?><br />
+			&nbsp;&nbsp;<?php echo translate('Subject') . ": " ;?><br />
 			&nbsp;&nbsp;<input name="subject" type="text" size="60"><br /><br />
-			&nbsp;&nbsp;<? echo translate('Message') . ": " ;?><br />
+			&nbsp;&nbsp;<?php echo translate('Message') . ": " ;?><br />
 			&nbsp;&nbsp;<textarea name="body" cols="60" rows="15"></textarea><br/>
 			&nbsp;&nbsp;<input type="submit" class="button" name="action" value="send"><br /><br />
 			</form>
@@ -60,7 +60,7 @@ function printsendmail(){
 		</tr>
 	</table>
 
-<?
+<?php
 }
 
 
