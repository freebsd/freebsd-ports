Index: portstools/tinderbox/webui/templates/paefchen/failed_buildports.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/failed_buildports.tpl:1.2.2.3 portstools/tinderbox/webui/templates/paefchen/failed_buildports.tpl:1.2.2.6
--- portstools/tinderbox/webui/templates/paefchen/failed_buildports.tpl:1.2.2.3	Sun Jan 18 15:09:30 2009
+++ portstools/tinderbox/webui/templates/paefchen/failed_buildports.tpl	Wed May  6 16:37:54 2009
@@ -20,14 +20,26 @@
 <?php if(!$no_list){?>
 <table>
 	<tr>
-		<th>Build</th>
-		<th>Port Directory</th>
-		<th>Version</th>
+		<th>
+			<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "build_id") ?>">Build</a>
+		</th>
+		<th>
+			<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "port_directory") ?>">Port Directory</a>
+		</th>
+		<th>
+			<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_built_version") ?>">Version</a>
+		</th>
 		<th style="width: 20px">&nbsp;</th>
-		<th>Reason</th>
+		<th>
+			<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_fail_reason") ?>">Reason</a>
+		</th>
 		<th>&nbsp;</th>
-		<th>Last Build Attempt</th>
-		<th>Last Successful Build</th>
+		<th>
+			<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_built") ?>">Last Build Attempt</a>
+		</th>
+		<th>
+			<a href="<?php echo  build_query_string($_SERVER['PHP_SELF'], $querystring, "sort", "last_successful_built") ?>">Last Successful Build</a>
+		</th>
 	</tr>
 <?php foreach($data as $row) {?>
 	<tr>
@@ -36,9 +48,9 @@
 		<td><?php echo $row['port_last_built_version']?></td>
 		<td class="<?php echo $row['status_field_class']?>"><?php echo $row['status_field_letter']?></td>
 		<?php $reason=$row['port_last_fail_reason']?>
-		<td class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
-		<?php $href=($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
-		<a href="<?php echo $href?>" class="<?php echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php echo $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
+		<td class="<?php if(!empty($reason)) echo "fail_reason_".$port_fail_reasons[$reason]['type']?>">
+		<?php $href=isset($port_fail_reasons[$reason]['link']) ? "index.php?action=display_failure_reasons&amp;failure_reason_tag=$reason#$reason" : "#"?>
+		<a href="<?php echo $href?>" class="<?php if(!empty($reason)) echo "fail_reason_".$port_fail_reasons[$reason]['type']?>" title="<?php if(!empty($reason)) $port_fail_reasons[$reason]['descr']?>"><?php echo $reason?></a>
 		</td>
 		<td>
 	<?php if($row['port_link_logfile']){?>
@@ -54,6 +66,14 @@
 	</tr>
 <?php }?>
 </table>
+<p>
+  <?php if($list_nr_prev!=-1){?>
+	  <a href="<?php echo build_query_string($_SERVER['PHP_SELF'], $querystring, "list_limit_offset", $list_nr_prev ) ?>">prev</a>
+  <?php }?>
+  <?php if($list_nr_next!=0){?>
+	  <a href="<?php echo build_query_string($_SERVER['PHP_SELF'], $querystring, "list_limit_offset", $list_nr_next ) ?>">next</a>
+  <?php }?>
+</p>
 <?php }else{?>
 <?php if(!$errors){?>
 	<p>There are no build failures at the moment.</p>
