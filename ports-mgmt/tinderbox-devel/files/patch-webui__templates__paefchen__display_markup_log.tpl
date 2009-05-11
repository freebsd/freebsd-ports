Index: portstools/tinderbox/webui/templates/paefchen/display_markup_log.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/display_markup_log.tpl:1.3.2.2 portstools/tinderbox/webui/templates/paefchen/display_markup_log.tpl:1.3.2.3
--- portstools/tinderbox/webui/templates/paefchen/display_markup_log.tpl:1.3.2.2	Sun Jan 18 15:09:30 2009
+++ portstools/tinderbox/webui/templates/paefchen/display_markup_log.tpl	Wed May  6 15:07:02 2009
@@ -1,5 +1,5 @@
 <?php
-$header_title = "$directory log";
+$header_title = $data['port_directory'] . " log";
 $topmenu = array(
 	$data['port_directory']	=> "index.php?action=describe_port&amp;id=$id",
 	'raw log'				=> $data['port_link_logfile']
