Index: portstools/tinderbox/webui/templates/paefchen/list_buildports.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/list_buildports.tpl:1.2.2.5 portstools/tinderbox/webui/templates/paefchen/list_buildports.tpl:1.2.2.7
--- portstools/tinderbox/webui/templates/paefchen/list_buildports.tpl:1.2.2.5	Sun Jan 18 15:09:30 2009
+++ portstools/tinderbox/webui/templates/paefchen/list_buildports.tpl	Wed May  6 15:48:33 2009
@@ -116,9 +116,9 @@
 		<td><?php echo $row['port_last_built_version']?></td>
 		<td class="<?php echo $row['status_field_class']?>"><?php echo $row['status_field_letter']?></td>
 		<?php $reason=$row['port_last_fail_reason']?>
-		<td class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
-		<?php $href=($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
-		<a href="<?php echo $href?>" class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
+		<td class="<?php if(!empty($reason))echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
+		<?php $href=isset($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
+		<a href="<?php echo $href?>" class="<?php if(!empty($reason))echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php if(!empty($reason))echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
 		</td>
 		<td>
 		<?php if($row['port_link_logfile']){?>
@@ -135,6 +135,14 @@
 	<?php }?>
 </table>
 <p>Total: <?php echo count($data)?></p>
+<p>
+  <?php if($list_nr_prev!=-1){?>
+      <a href="index.php?action=<?php echo $_REQUEST['action'] ?>&build=<?php if (isset($_REQUEST['build']))echo $_REQUEST['build'] ?>&sort=<?php if (isset($_REQUEST['sort']))echo $_REQUEST['sort'] ?>&search_port_name=<?php if (isset($_REQUEST['search_port_name']))echo $_REQUEST['search_port_name'] ?>&list_limit_offset=<?php echo $list_nr_prev ?> ">prev</a>
+  <?php }?>
+  <?php if($list_nr_next!=0){?>
+      <a href="index.php?action=<?php echo $_REQUEST['action'] ?>&build=<?php if (isset($_REQUEST['build']))echo $_REQUEST['build'] ?>&sort=<?php if (isset($_REQUEST['sort']))echo $_REQUEST['sort'] ?>&search_port_name=<?php if (isset($_REQUEST['search_port_name']))echo $_REQUEST['search_port_name'] ?>&list_limit_offset=<?php echo $list_nr_next ?> ">next</a>
+  <?php }?>
+</p>
 <?php }else{?>
 	<?php if(!$errors){?>
 		<p>No ports are being built.</p>
