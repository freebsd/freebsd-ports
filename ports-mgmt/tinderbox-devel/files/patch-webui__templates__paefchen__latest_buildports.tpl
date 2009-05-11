Index: portstools/tinderbox/webui/templates/paefchen/latest_buildports.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/latest_buildports.tpl:1.1.2.4 portstools/tinderbox/webui/templates/paefchen/latest_buildports.tpl:1.1.2.7
--- portstools/tinderbox/webui/templates/paefchen/latest_buildports.tpl:1.1.2.4	Sun Jan 18 15:09:30 2009
+++ portstools/tinderbox/webui/templates/paefchen/latest_buildports.tpl	Wed May  6 16:52:30 2009
@@ -4,7 +4,10 @@
 	$header_title .= " in $build_name";
 $topmenu = array(
 	'Current'	=> '#current',
-	'Latest'	=> '#latest'
+	'Latest'	=> '#latest',
+	'All Build Failures'			=> 'index.php?action=failed_buildports',
+	'All Failures'		=> 'index.php?action=bad_buildports',
+	'RSS Feed'						=> 'index.php?action=latest_buildports_rss'
 );
 include 'header.inc.tpl'
 ?>
@@ -47,9 +50,9 @@
 				<td><?php echo $row['port_last_built_version']?></td>
 				<td class="<?php echo $row['status_field_class']?>"><?php echo $row['status_field_letter']?></td>
 				<?php $reason=$row['port_last_fail_reason']?>
-				<td class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
-				<?php $href=($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
-				<a href="<?php echo $href?>" class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
+				<td class="<?php if(!empty($reason)) echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
+				<?php $href=isset($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
+				<a href="<?php echo $href?>" class="<?php if(!empty($reason)) echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php if(!empty($reason)) echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
 				</td>
 				<td>
 					<?php if($row['port_link_logfile']){?>
