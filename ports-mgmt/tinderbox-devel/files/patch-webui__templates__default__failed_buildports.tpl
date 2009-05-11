Index: portstools/tinderbox/webui/templates/default/failed_buildports.tpl
diff -u portstools/tinderbox/webui/templates/default/failed_buildports.tpl:1.8.2.3 portstools/tinderbox/webui/templates/default/failed_buildports.tpl:1.8.2.5
--- portstools/tinderbox/webui/templates/default/failed_buildports.tpl:1.8.2.3	Sun Jan 18 15:09:29 2009
+++ portstools/tinderbox/webui/templates/default/failed_buildports.tpl	Wed May  6 16:37:53 2009
@@ -1,7 +1,7 @@
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
 <html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
 <head>
-<!-- $MCom: portstools/tinderbox/webui/templates/default/failed_buildports.tpl,v 1.8.2.3 2009/01/18 20:09:29 beat Exp $ //-->
+<!-- $MCom: portstools/tinderbox/webui/templates/default/failed_buildports.tpl,v 1.8.2.5 2009/05/06 20:37:53 beat Exp $ //-->
 <title><?php echo $tinderbox_name?></title>
 <link href="<?php echo $templatesuri?>/tinderstyle.css" rel="stylesheet" type="text/css" />
 </head>
@@ -34,14 +34,26 @@
 <?php if(!$no_list){?>
 	<table>
 		<tr>
-			<th>Build</th>
-			<th>Port Directory</th>
-			<th>Version</th>
+			<th>
+				<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "build_id") ?>">Build</a>
+			</th>
+			<th>
+				<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "port_directory") ?>">Port Directory</a>
+			</th>
+			<th>
+				<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_built_version") ?>">Version</a>
+			</th>
 			<th style="width: 20px">&nbsp;</th>
-			<th>Reason</th>
+			<th>
+				<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_fail_reason") ?>">Reason</a>
+			</th>
 			<th>&nbsp;</th>
-			<th>Last Build Attempt</th>
-			<th>Last Successful Build</th>
+			<th>
+				<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_built") ?>">Last Build Attempt</a>
+			</th>
+			<th>
+				<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_successful_built") ?>">Last Successful Build</a>
+			</th>
 		</tr>
 
 		<?php foreach($data as $row) {?>
@@ -51,9 +63,9 @@
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
@@ -69,6 +81,14 @@
 			</tr>
 		<?php }?>
 	</table>
+	<p>
+		<?php if($list_nr_prev!=-1){?>
+			<a href="<?php echo build_query_string($_SERVER['PHP_SELF'], $querystring, "list_limit_offset", $list_nr_prev ) ?>">prev</a>
+		<?php }?>
+		<?php if($list_nr_next!=0){?>
+			<a href="<?php echo build_query_string($_SERVER['PHP_SELF'], $querystring, "list_limit_offset", $list_nr_next ) ?>">next</a>
+		<?php }?>
+	</p>
 <?php }else{?>
 	<?php if(!$errors){?>
 		<p>There are no build failures at the moment.</p>
