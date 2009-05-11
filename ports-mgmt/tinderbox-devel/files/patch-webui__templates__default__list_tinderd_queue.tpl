Index: portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl
diff -u portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl:1.11.2.4 portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl:1.11.2.5
--- portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl:1.11.2.4	Wed Feb 11 03:41:21 2009
+++ portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl	Wed May  6 15:07:01 2009
@@ -1,7 +1,7 @@
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
 <html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
 <head>
-<!-- $MCom: portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl,v 1.11.2.4 2009/02/11 08:41:21 beat Exp $ //-->
+<!-- $MCom: portstools/tinderbox/webui/templates/default/list_tinderd_queue.tpl,v 1.11.2.5 2009/05/06 19:07:01 beat Exp $ //-->
 <title><?php echo $tinderbox_name?></title>
 <link href="<?php echo $templatesuri?>/tinderstyle.css" rel="stylesheet" type="text/css" />
 </head>
@@ -61,7 +61,7 @@
 
 		<form method="post" action="index.php">
 		<input type="hidden" name="action" value="add_tinderd_queue" />
-		<input type="hidden" name="entry_id" value="<?php echo $row['entry_id']?>" />
+		<input type="hidden" name="entry_id" value="<?php if(!empty($row['entry_id']))echo $row['entry_id']?>" />
 		<input type="hidden" name="filter_build_id" value="<?php echo $build_id?>" />
 		<tr>
 			<td>
