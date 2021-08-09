--- templates/summary.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/summary.template.php
@@ -33,12 +33,12 @@ function showSummary($count_array) {
       		<table width="100%" border="0" cellspacing="1" cellpadding="0">
         		<tr>
 			<td colspan="5" class="tableTitle">
-			<? echo translate($_SESSION['sessionNav']); ?> 
+			<?php echo translate($_SESSION['sessionNav']); ?> 
 			</td>
 
         		<td class="tableTitle">
             		<div align="right">
-              			<? $link->doLink('javascript: help(\'msg_summary\');', '?', '', 'color: #FFFFFF;',
+              			<?php $link->doLink('javascript: help(\'msg_summary\');', '?', '', 'color: #FFFFFF;',
 					translate('Help') . ' - ' . translate($_SESSION['sessionNav'])) ?>
             		</div>
         		</td>
@@ -52,29 +52,29 @@ function showSummary($count_array) {
 				<!-- Print table's headers -->
         <tr class="rowHeaders">
 					<td width="15%">
-						<? echo translate('Date'); ?>
+						<?php echo translate('Date'); ?>
 					</td>
 					<td width="14%">
-						<? echo translate('Spam'); ?>
+						<?php echo translate('Spam'); ?>
 					</td>
        		<td width="14%">
-						<? echo translate('Banned'); ?>
+						<?php echo translate('Banned'); ?>
 					</td>
        		<td width="14%">
- 						<? echo translate('Viruses'); ?>
+ 						<?php echo translate('Viruses'); ?>
 					</td>
        		<td width="14%">
- 						<? echo translate('Bad Headers'); ?>
+ 						<?php echo translate('Bad Headers'); ?>
 					</td>
        		<td width="14%">
- 						<? echo translate('Pending Requests'); ?>
+ 						<?php echo translate('Pending Requests'); ?>
 					</td>
        		<td width="15%">
- 						<? echo translate('Total'); ?>
+ 						<?php echo translate('Total'); ?>
 					</td>
    			</tr>
 			
-			<?  $i = 0;
+			<?php  $i = 0;
 					foreach ($count_array as $key => $val) { 
 						echo '<tr class="' . 'cellColor' . ($i++%2) . ' align="center">';
 						echo ($key == 'Total' ? '<td class="rowTotals">' : '<td class="rowNumValues">') . "$key</td> \n";
@@ -89,7 +89,7 @@ function showSummary($count_array) {
 		</td>
 		</tr>
 	</table>
-<? 
+<?php 
 }
 
 ?>
