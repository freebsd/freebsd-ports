Index: portstools/tinderbox/webui/templates/default/latest_buildports.tpl
diff -u portstools/tinderbox/webui/templates/default/latest_buildports.tpl:1.10.2.4 portstools/tinderbox/webui/templates/default/latest_buildports.tpl:1.10.2.7
--- portstools/tinderbox/webui/templates/default/latest_buildports.tpl:1.10.2.4	Sun Jan 18 15:09:29 2009
+++ portstools/tinderbox/webui/templates/default/latest_buildports.tpl	Wed May  6 16:52:29 2009
@@ -1,7 +1,7 @@
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
 <html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
 <head>
-<!-- $MCom: portstools/tinderbox/webui/templates/default/latest_buildports.tpl,v 1.10.2.4 2009/01/18 20:09:29 beat Exp $ //-->
+<!-- $MCom: portstools/tinderbox/webui/templates/default/latest_buildports.tpl,v 1.10.2.7 2009/05/06 20:52:29 beat Exp $ //-->
 <script language="JavaScript">
 	function reloadpage() {
 	    document.location.reload();
@@ -48,9 +48,9 @@
 				<td><?php echo $row['port_last_built_version']?></td>
 				<td class="<?php echo $row['status_field_class']?>"><?php echo $row['status_field_letter']?></td>
 				<?php $reason=$row['port_last_fail_reason']?>
-				<td class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
-				<?php $href=($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
-				<a href="<?php echo $href?>" class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
+				<td class="<?php if(!empty($port_fail_reasons[$reason]['type']))echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
+				<?php $href=isset($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
+				<a href="<?php echo $href?>" class="<?php if(!empty($port_fail_reasons[$reason]['type']))echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php if(!empty($port_fail_reasons[$reason]['descr']))echo $port_fail_reasons[$reason]['descr']?>"><?php $reason?></a>
 				</td>
 				<td>
 					<?php if($row['port_link_logfile']){?>
@@ -73,6 +73,11 @@
 	<?php }?>
 <?php }?>
 
+<p>
+<a href="index.php?action=failed_buildports">All Build Failures</a><br />
+<a href="index.php?action=bad_buildports">All Failures</a><br />
+<a href="index.php?action=latest_buildports_rss">RSS Feed</a><br />
+<p>
 <p>Local time: <?php echo $local_time?></p>
 <p style="color:#FF0000;font-size:10px;"><?php echo $ui_elapsed_time?></p>
 <?php echo $display_login?>
