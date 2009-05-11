Index: portstools/tinderbox/webui/templates/paefchen/list_tinderd_queue.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/list_tinderd_queue.tpl:1.2.2.4 portstools/tinderbox/webui/templates/paefchen/list_tinderd_queue.tpl:1.2.2.6
--- portstools/tinderbox/webui/templates/paefchen/list_tinderd_queue.tpl:1.2.2.4	Wed Feb 11 03:41:22 2009
+++ portstools/tinderbox/webui/templates/paefchen/list_tinderd_queue.tpl	Wed May  6 15:07:02 2009
@@ -4,12 +4,13 @@
 ?>
 <!-- $Paefchen: FreeBSD/tinderbox/webui/templates/paefchen/list_tinderd_queue.tpl,v 1.1 2008/01/05 12:25:17 as Exp $ //-->
 <div class="subcontent">
-	<form method="get" action="index.php">
-	<input type="hidden" name="action" value="list_tinderd_queue" />
 	<table>
 		<tr>
 			<th>Build</th>
 			<td>
+				<form method="get" action="index.php">
+				<fieldset>
+				<input type="hidden" name="action" value="list_tinderd_queue" />
 				<select name="filter_build_id">
 					<option></option>
 <?php foreach($all_builds as $build) {?>
@@ -17,11 +18,30 @@
 <?php }?>
 				</select>
 				<input type="submit" name="display" value="display" /> 
+				</fieldset>
+				</form>
+			</td>
+			<td style="background-color: #FFFFFF; width: 20px">&nbsp;</td>
+				<td>
+				<form method="post" action="index.php">
+				<fieldset>
+					<input type="hidden" name="action" value="delete_tinderd_queue" />
+					<input type="hidden" name="filter_build_id" value="<?php echo $build_id?>" />
+					<input type="submit" name="delete_tinderd_queue" value="delete all built" />
+				</fieldset>
+				</form>
+				</td>
+				<td style="background-color: #FFFFFF; width: 20px">&nbsp;</td>
+				<td>
+				<form method="post" action="index.php">
+				<fieldset>
+					<input type="hidden" name="action" value="delete_tinderd_queue" />
+					<input type="submit" name="delete_tinderd_queue" value="delete all" />
+				</fieldset>
+				</form>
 			</td>
 		</tr>
 	</table>
-	</form>
-</div>
 
 <?php if($errors){?>
 	<p style="color:#FF0000">
@@ -30,15 +50,9 @@
 	<?php }?>
 	</p>
 <?php }?>
-<p>
-	<form method="post" action="index.php">
-		<input type="hidden" name="action" value="delete_tinderd_queue" />
-		<input type="hidden" name="filter_build_id" value="<?php echo $build_id?>" />
-		<input type="submit" name="delete_tinderd_queue" value="delete all built" />
-		<input type="submit" name="delete_tinderd_queue" value="delete all" />
-	</form>
-</p>
-<br />
+
+</div>
+
 <table>
 	<tr>
 		<th>Build</th>
@@ -52,8 +66,9 @@
 		<th>&nbsp;</th>
 	</tr>
 	<form method="post" action="index.php">
+	<fieldset>
 	<input type="hidden" name="action" value="add_tinderd_queue" />
-	<input type="hidden" name="entry_id" value="<?php echo $row['entry_id']?>" />
+	<input type="hidden" name="entry_id" value="<?php if(!empty($row['entry_id']))echo $row['entry_id']?>" />
 	<input type="hidden" name="filter_build_id" value="<?php echo $build_id?>" />
 	<tr>
 		<td>
@@ -78,11 +93,13 @@
 		</td>
 		<td colspan="3"><input type="submit" name="add_tinderd_queue" value="add" /></td>
 	</tr>
+	</fieldset>
 	</form>
 <?php if(!$no_list){?>
 
 		<?php foreach($entries as $row) {?>
 			<form method="post" action="index.php">
+			<fieldset>
 			<input type="hidden" name="action" value="change_tinderd_queue" />
 			<input type="hidden" name="entry_id" value="<?php echo $row['entry_id']?>" />
 			<input type="hidden" name="filter_build_id" value="<?php echo $build_id?>" />
@@ -135,6 +152,7 @@
 					<?php }?>
 				</td>
 			</tr>
+			</fieldset>
 			</form>
 		<?php }?>
 <?php }?>
