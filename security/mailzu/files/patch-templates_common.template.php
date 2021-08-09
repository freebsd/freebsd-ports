--- templates/common.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/common.template.php
@@ -47,10 +47,10 @@ function showQuickLinks() {
       <table width="100%" border="0" cellspacing="0" cellpadding="0">
         <tr>
           <td class="tableTitle" style="background-color:#0F93DF;">
-		    <?=translate('My Quick Links')?>
+		    <?php echo translate('My Quick Links')?>
 		  </td>
           <td class="tableTitle" style="background-color:#0F93DF;"><div align="right">
-              <? $link->doLink("javascript: help('quick_links');", '?', '', 'color: #FFFFFF', translate('Help') . ' - ' . translate('My Quick Links')) ?>
+              <?php $link->doLink("javascript: help('quick_links');", '?', '', 'color: #FFFFFF', translate('Help') . ' - ' . translate('My Quick Links')) ?>
             </div>
           </td>
         </tr>
@@ -58,12 +58,12 @@ function showQuickLinks() {
       <table width="100%" border="0" cellspacing="0" cellpadding="0">
         <tr style="padding: 5px;" class="cellColor">
           <td colspan="2">
-		<? echo "Quarantine Summary" == $_SESSION['sessionNav'] ? 
+		<?php echo "Quarantine Summary" == $_SESSION['sessionNav'] ? 
 			' <p class="selectedLink"><b>&raquo;</b>':
 			" <p><b>&#8250;</b>\t";
               	$link->doLink('summary.php', translate('Quarantine Summary')) ?>
             	</p>
-		<? echo "My Quarantine" == $_SESSION['sessionNav'] ? 
+		<?php echo "My Quarantine" == $_SESSION['sessionNav'] ? 
 			' <p class="selectedLink"><b>&raquo;</b>':
 			" <p><b>&#8250;</b>\t";
               	$link->doLink('messagesIndex.php?ctype=A', translate('My Quarantine'));
@@ -78,7 +78,7 @@ function showQuickLinks() {
 		?>
             	</p>
 		<br>
-		<? if (Auth::isMailAdmin()) {
+		<?php if (Auth::isMailAdmin()) {
 		     if ($conf['app']['siteSummary']) {
   		       echo "Site Quarantine Summary" == $_SESSION['sessionNav'] ? 
 		  	  ' <p class="selectedLink"><b>&raquo;</b>':
@@ -108,11 +108,11 @@ function showQuickLinks() {
 		}
 		?>
             	<p><b>&#8250;</b>
-              	<? $link->doLink('javascript: help();', translate('Help')) ?>
+              	<?php $link->doLink('javascript: help();', translate('Help')) ?>
             	</p>
 		<br>
             	<p><b>&#8250;</b>
-              	<? $link->doLink('index.php?logout=true', translate('Log Out')) ?>
+              	<?php $link->doLink('index.php?logout=true', translate('Log Out')) ?>
             	</p>
           </td>
         </tr>
@@ -120,7 +120,7 @@ function showQuickLinks() {
     </td>
   </tr>
 </table>
-<?
+<?php
 }
 
 /**
@@ -164,14 +164,14 @@ function startQuickLinksCol() {
 <table width="100%" border="0" cellpadding="0" cellspacing="0">
 <tr>
 <td style="vertical-align:top; width:16%; border:solid 2px #0F93DF; background-color:#FFFFFF;">
-<? 
+<?php
 }
 
 function startDataDisplayCol() {
 ?>
 </td>
 <td style="padding-left:5px; vertical-align:top;">
-<?
+<?php
 }
 
 function endDataDisplayCol() {
@@ -179,7 +179,7 @@ function endDataDisplayCol() {
 </td>
 </tr>
 </table>
-<?
+<?php
 }
 
 /**
@@ -191,7 +191,7 @@ function printActionButtons( $printDeleteAll = true ) 
 ?>
 <table width="100%" border="0" cellspacing="1" cellpadding="0">
 <tr>
-<? 
+<?php
 	echo "<td align=\"left\"><input type=\"submit\" class=\"button\" name=\"action\" value=\"";
 	if ($_SESSION['sessionNav'] == "My Pending Requests") {
 		echo ( Auth::isMailAdmin() ? translate('Release') : translate('Cancel Request') );
@@ -201,14 +201,14 @@ function printActionButtons( $printDeleteAll = true ) 
 	}
 	echo "\"></td>";
 ?>
-	<td align="right"><input type="submit" class="button" name="action" value="<? echo translate('Delete'); ?>">
-<? 	if ( $printDeleteAll )
+	<td align="right"><input type="submit" class="button" name="action" value="<?php echo translate('Delete'); ?>">
+<?php 	if ( $printDeleteAll )
 		echo "<input type=\"submit\" class=\"button\" name=\"action\" value=\"".translate('Delete All')."\">";
 ?>
 	</td>
 </tr>
 </table>
-<?
+<?php
 }
 
 /**
@@ -223,17 +223,17 @@ function printReportButtons( $query_string, $error_arr
 <form name="error_report_form" action="sendErrorReport.php" method="POST">
 <table width="100%" border="0" cellspacing="1" cellpadding="0">
 <tr>
-	<input type="hidden" name="query_string" value="<? echo $query_string; ?> ">
-	<input type="hidden" name="serialized_error_array" value="<? echo $serialized_error_array; ?>">
-	<input type="hidden" name="process_action" value="<? echo $process_action ;?>">
+	<input type="hidden" name="query_string" value="<?php echo $query_string; ?> ">
+	<input type="hidden" name="serialized_error_array" value="<?php echo $serialized_error_array; ?>">
+	<input type="hidden" name="process_action" value="<?php echo $process_action ;?>">
 	<td><center>
-		<input type="submit" class="button" name="action" value="<? echo translate('Send report and go back'); ?>">&nbsp;
-		<input type="submit" class="button" name="action" value="<? echo translate('Go back'); ?>">
+		<input type="submit" class="button" name="action" value="<?php echo translate('Send report and go back'); ?>">&nbsp;
+		<input type="submit" class="button" name="action" value="<?php echo translate('Go back'); ?>">
 	</center></td>
 </tr>
 </table>
 </form>
-<?
+<?php
 }
 
 /**
@@ -243,10 +243,10 @@ function printReportButtons( $query_string, $error_arr
 function printMessage($message) {
 	$id = urlencode($message);
 ?>
-	<div align="center" id="<? echo $id; ?>" style="display:block;">
-		<H4><? echo $message; ?></H4>
+	<div align="center" id="<?php echo $id; ?>" style="display:block;">
+		<H4><?php echo $message; ?></H4>
 	</div>
-<? 
+<?php 
 	ob_flush();
 	flush();
 }
