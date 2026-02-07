--- templates/quarantine.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/quarantine.template.php
@@ -56,10 +56,10 @@ function showMessagesTable($content_type, $res, $page,
 
 		<form name="messages_process_form" action="messagesProcessing.php" method="POST">
 
-		<input type="hidden" name="ctype" value="<? echo $content_type; ?>">
-		<input type="hidden" name="query_string" value="<? echo $query_string; ?>">
+		<input type="hidden" name="ctype" value="<?php echo $content_type; ?>">
+		<input type="hidden" name="query_string" value="<?php echo $query_string; ?>">
 
-		<? // Draw 'Release', 'Delete' and 'Delete All' buttons 
+		<?php // Draw 'Release', 'Delete' and 'Delete All' buttons 
 		printActionButtons((! CmnFns::didSearch() && ! ("Site Quarantine" == $_SESSION['sessionNav'])) );
 		// Draw 'Select All, Clear All' and multi pages links 
 		printSelectAndPager($pager_html);
@@ -74,13 +74,13 @@ function showMessagesTable($content_type, $res, $page,
       			<table width="100%" border="0" cellspacing="1" cellpadding="0">
         			<tr>
 				<td colspan="5" class="tableTitle">
-				<? echo translate('Showing messages', 
+				<?php echo translate('Showing messages', 
 					array( number_format($page*$sizeLimit+1), number_format($page*$sizeLimit+$end_entry), $count )); ?>
 				</td>
 
         			<td class="tableTitle">
             			<div align="right">
-              				<? $link->doLink('javascript: help(\'msg_index\');', '?', '', 'color: #FFFFFF;',
+              				<?php $link->doLink('javascript: help(\'msg_index\');', '?', '', 'color: #FFFFFF;',
 						translate('Help') . ' - ' . translate('My Quarantine')) ?>
             			</div>
         			</td>
@@ -93,43 +93,43 @@ function showMessagesTable($content_type, $res, $page,
 				<!-- Print table's headers -->
 			<tr class="rowHeaders">
 				<td width="3%">&nbsp;</td>
-				<? if ( (count($_SESSION['sessionMail']) > 1) || ((Auth::isMailAdmin()) && 
+				<?php if ( (count($_SESSION['sessionMail']) > 1) || ((Auth::isMailAdmin()) && 
 				      ("Site Quarantine" == $_SESSION['sessionNav'] || "Site Pending Requests" == $_SESSION['sessionNav']))) { ?>
-				<td width="15%" <? echo "recip.email"==$order?' class="reservedCell"':''; ?>>
-					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<td width="15%" <?php echo "recip.email"==$order?' class="reservedCell"':''; ?>>
+					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=recip.email&amp;vert=' . $new_vert, translate('To'), '', '', $mouseover_text) ?>
 				</td>
-				<? } ?>
-				<td width="15%" <? echo "from_addr"==$order?' class="reservedCell"':''; ?>>
- 					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<?php } ?>
+				<td width="15%" <?php echo "from_addr"==$order?' class="reservedCell"':''; ?>>
+ 					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=from_addr&amp;vert=' . $new_vert, translate('From'), '', '', $mouseover_text) ?>
 				</td>
-				<td width="40%" <? echo "msgs.subject"==$order?' class="reservedCell"':''; ?>>
-					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<td width="40%" <?php echo "msgs.subject"==$order?' class="reservedCell"':''; ?>>
+					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=msgs.subject&amp;vert=' . $new_vert, translate('Subject'), '', '', $mouseover_text) ?>
 				</td>
-				<td width="10%" <? echo "msgs.time_num"==$order?' class="reservedCell"':''; ?>>
-					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<td width="10%" <?php echo "msgs.time_num"==$order?' class="reservedCell"':''; ?>>
+					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=msgs.time_num&amp;vert=' . $new_vert, translate('Date'), '', '', $mouseover_text) ?>
 				</td>
-				<td width="7%" <? echo "spam_level"==$order?' class="reservedCell"':''; ?>>
-					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<td width="7%" <?php echo "spam_level"==$order?' class="reservedCell"':''; ?>>
+					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=spam_level&amp;vert=' . $new_vert, translate('Score'), '', '', $mouseover_text) ?>
 				</td>
-				<td width="10%" <? echo "msgs.content"==$order?' class="reservedCell"':''; ?>>
-					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<td width="10%" <?php echo "msgs.content"==$order?' class="reservedCell"':''; ?>>
+					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=msgs.content&amp;vert=' . $new_vert, translate('Content Type'), '', '', $mouseover_text) ?>
 				</td>
-					<? if ( (Auth::isMailAdmin()) && 
+					<?php if ( (Auth::isMailAdmin()) && 
 				      ("Site Quarantine" == $_SESSION['sessionNav'] || "Site Pending Requests" == $_SESSION['sessionNav'])) { ?>
-				<td width="10%" <? echo "mail_id"==$order?' class="reservedCell"':''; ?>>
-					<? $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
+				<td width="10%" <?php echo "mail_id"==$order?' class="reservedCell"':''; ?>>
+					<?php $link->doLink($_SERVER['PHP_SELF'] . '?' . CmnFns::querystring_exclude_vars( array('order','vert'))
 					. '&amp;order=mail_id&amp;vert=' . $new_vert, translate('Mail ID'), '', '', $mouseover_text) ?>
 				</td>
-				<? } ?>
+				<?php } ?>
 			</tr>
 
-        			<? // For each line in table, print message fields
+        			<?php // For each line in table, print message fields
 				for ($i = $start_entry;  $i < $end_entry; $i++) {
 					$rs = $res[$i];
 					// Make sure that there is a clickable subject
@@ -143,7 +143,7 @@ function showMessagesTable($content_type, $res, $page,
         				echo "<tr class=\"$class\" align=\"center\">";
 
 					echo '  <td><input type="checkbox" onclick="ColorRow(this,\'lightyellow\')" 
-						name="mail_id_array[]" value="' . $rs['mail_id'] . '_' . $rs['email'] . '"></td>';
+						name="mail_id_array[]" value="' . $rs['mail_id'] . '__' . $rs['email'] . '"></td>';
 					if ( (count($_SESSION['sessionMail']) > 1) || (Auth::isMailAdmin() && 
 					   ("Site Quarantine" == $_SESSION['sessionNav'] || "Site Pending Requests" == $_SESSION['sessionNav']))) {
 						echo '  <td>' . $to . '</td>';
@@ -192,7 +192,7 @@ function showMessagesTable($content_type, $res, $page,
   			</tr>
 		</table>
 
-		<? // Draw 'Select All, Clear All' and multi pages links 
+		<?php // Draw 'Select All, Clear All' and multi pages links 
 		printSelectAndPager($pager_html);
 		// Draw 'Release', 'Delete' and 'Delete All' buttons
 		printActionButtons((! CmnFns::didSearch() && ! ("Site Quarantine" == $_SESSION['sessionNav'])) );
@@ -200,7 +200,7 @@ function showMessagesTable($content_type, $res, $page,
 		unset($res); ?>
 
 		</form>
-	<? } else {
+	<?php } else {
 		echo '<table width="100%" border="0" cellspacing="1" cellpadding="0">';
 		echo '<tr><td align="center">' . translate('There are no matching records.') . '</td></tr>';
 		echo '</table>';
@@ -221,25 +221,25 @@ function printSearchEngine($content_type, $submit_page
       <table width="100%" border="0" cellspacing="1" cellpadding="0">
       	<tr>
 	  <td class="tableTitle">
-	    <a href="javascript: void(0);" onclick="showHideSearch('search');">&#8250; <?=translate('Search')?></a>
+	    <a href="javascript: void(0);" onclick="showHideSearch('search');">&#8250; <?php echo translate('Search')?></a>
 	  </td>
 	  <td class="tableTitle">
             <div align="right">
-              <? $link->doLink('javascript: help(\'search\');', '?', '', 'color: #FFFFFF;', translate('Help') . ' - ' . translate('My Re
+              <?php $link->doLink('javascript: help(\'search\');', '?', '', 'color: #FFFFFF;', translate('Help') . ' - ' . translate('My Re
 servations')) ?>
             </div>
           </td>
 	</tr>
 </table>
-<div id="search" style="display: <?= getShowHide('search') ?>">
+<div id="search" style="display: <?php echo getShowHide('search') ?>">
   <table width="100%" border="0" cellspacing="1" cellpadding="0">
-    <tr class="cellColor"><td><center><? CmnFns::searchEngine($content_type, $submit_page, $full_search); ?></center></td></tr>
+    <tr class="cellColor"><td><center><?php CmnFns::searchEngine($content_type, $submit_page, $full_search); ?></center></td></tr>
   </table>
 </div>
     </td>
   </tr>
 </table>
-<?
+<?php
 }
 
 
@@ -253,12 +253,12 @@ function printSelectAndPager($pager_html) {
 <table class="stdFont" width="100%" border="0" cellspacing="1" cellpadding="0">
 <tr>
 <td>
-	<a href="javascript:CheckAll(document.messages_process_form);"><? echo translate('Select All'); ?></a>&nbsp;|&nbsp;
-	<a href="javascript:CheckNone(document.messages_process_form);"><? echo translate('Clear All'); ?></a>
+	<a href="javascript:CheckAll(document.messages_process_form);"><?php echo translate('Select All'); ?></a>&nbsp;|&nbsp;
+	<a href="javascript:CheckNone(document.messages_process_form);"><?php echo translate('Clear All'); ?></a>
 </td>
 <td>
 	<div align="right">
-<?
+<?php
 	// Draw the paging links if more than 1 page
 	echo $pager_html . "\n";
 ?>
@@ -266,7 +266,7 @@ function printSelectAndPager($pager_html) {
 </td>
 </tr>
 </table>
-<?
+<?php
 }
 
 /**
@@ -280,14 +280,14 @@ function printNoMesgWarning() {
 		<tr><td class="tableBorder">
 			<table width="100%" border="0" cellspacing="1" cellpadding="0">
 				<tr class="cellColor"><td>
-					<center><? echo translate('No message was selected'); ?><br>
-					<? $link->doLink('javascript: history.back();','&#8249;&#8249; ' . translate('BackMessageIndex'), '', '',
+					<center><?php echo translate('No message was selected'); ?><br>
+					<?php $link->doLink('javascript: history.back();','&#8249;&#8249; ' . translate('BackMessageIndex'), '', '',
 						translate('BackMessageIndex')); ?></center>
 				</td></tr>
 			</table>
 		</td></tr>
 	</table>
-<?
+<?php
 }
 
 /**
@@ -308,7 +308,7 @@ function showFailedMessagesTable($action, $content_typ
 				<table width="100%" border="0" cellspacing="1" cellpadding="0">
 				<tr>
 			<td colspan="5" class="tableTitle">
-			<? 	if ( $action == translate('Release') || $action == translate('Release/Request release') )
+			<?php 	if ( $action == translate('Release') || $action == translate('Release/Request release') )
 					echo translate('A problem occured when trying to release the following messages');
 				elseif ( $action == translate('Delete') || $action == translate('Delete All') )
 					echo translate('A problem occured when trying to delete the following messages');
@@ -316,7 +316,7 @@ function showFailedMessagesTable($action, $content_typ
 			</td>
 					<td class="tableTitle">
 							<div align="right">
-								<? $link->doLink('javascript: help(\'msg_index\');', '?', '', 'color: #FFFFFF;', translate('Help') ) ?>
+								<?php $link->doLink('javascript: help(\'msg_index\');', '?', '', 'color: #FFFFFF;', translate('Help') ) ?>
 							</div>
 					</td>
 				</tr>
@@ -325,17 +325,17 @@ function showFailedMessagesTable($action, $content_typ
 		<!-- Print table headers -->
 					<table width="100%" border="0" cellspacing="1" cellpadding="0">
 					<tr class="rowHeaders">
-							<td width="20%"><? echo translate('From'); ?></td>
-							<td width="30%"><? echo translate('Subject'); ?></td>
-							<td width="10%"><? echo translate('Date'); ?></td>
-			<? if ( 'S' == $content_type ) { ?>
-							<td width="10%"><? echo translate('Score'); ?></td>
-			<? } ?>
-							<td width="30%"><? echo translate('Status'); ?></td>
+							<td width="20%"><?php echo translate('From'); ?></td>
+							<td width="30%"><?php echo translate('Subject'); ?></td>
+							<td width="10%"><?php echo translate('Date'); ?></td>
+			<?php if ( 'S' == $content_type ) { ?>
+							<td width="10%"><?php echo translate('Score'); ?></td>
+			<?php } ?>
+							<td width="30%"><?php echo translate('Status'); ?></td>
 		</tr>
 
 		<!-- Print table rows -->
-		<?
+		<?php
 		for ($i = 0; is_array($res) && $i < count($res); $i++) {
 			$rs = $res[$i];
 			$subject = $rs['subject'] ? $rs['subject'] : '(none)';
@@ -353,7 +353,7 @@ function showFailedMessagesTable($action, $content_typ
 		</td>
 	</tr>
 	</table>	
-<?
+<?php
 }
 
 ?>
