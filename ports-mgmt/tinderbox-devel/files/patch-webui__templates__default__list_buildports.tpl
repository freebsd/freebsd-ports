Index: portstools/tinderbox/webui/templates/default/list_buildports.tpl
diff -u portstools/tinderbox/webui/templates/default/list_buildports.tpl:1.11.2.5 portstools/tinderbox/webui/templates/default/list_buildports.tpl:1.11.2.6
--- portstools/tinderbox/webui/templates/default/list_buildports.tpl:1.11.2.5	Sun Jan 18 15:09:29 2009
+++ portstools/tinderbox/webui/templates/default/list_buildports.tpl	Wed May  6 15:07:01 2009
@@ -1,7 +1,7 @@
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
 <html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
 <head>
-<!-- $MCom: portstools/tinderbox/webui/templates/default/list_buildports.tpl,v 1.11.2.5 2009/01/18 20:09:29 beat Exp $ //-->
+<!-- $MCom: portstools/tinderbox/webui/templates/default/list_buildports.tpl,v 1.11.2.6 2009/05/06 19:07:01 beat Exp $ //-->
 <title><?php echo $tinderbox_name?></title>
 <link href="<?php echo $templatesuri?>/tinderstyle.css" rel="stylesheet" type="text/css" />
 <link rel="alternate" type="application/rss+xml" title="<?php echo $tinderbox_name?> (RSS)" href="index.php?action=latest_buildports_rss" />
@@ -89,9 +89,9 @@
 				<td><?php echo $row['port_last_built_version']?></td>
 				<td class="<?php echo $row['status_field_class']?>"><?php echo $row['status_field_letter']?></td>
 				<?php $reason=$row['port_last_fail_reason']?>
-				<td class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
-				<?php $href=($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
-				<a href="<?php echo $href?>" class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
+				<td class="<?php if(!empty($port_fail_reasons[$reason]['type']))echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
+				<?php $href=isset($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
+				<a href="<?php echo $href?>" class="<?php if(!empty($port_fail_reasons[$reason]['type']))echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php if(!empty($port_fail_reasons[$reason]['descr']))echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
 				</td>
 				<td>
 					<?php if($row['port_link_logfile']){?>
