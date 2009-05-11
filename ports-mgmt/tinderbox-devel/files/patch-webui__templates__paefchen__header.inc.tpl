Index: portstools/tinderbox/webui/templates/paefchen/header.inc.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/header.inc.tpl:1.2.2.3 portstools/tinderbox/webui/templates/paefchen/header.inc.tpl:1.2.2.4
--- portstools/tinderbox/webui/templates/paefchen/header.inc.tpl:1.2.2.3	Sun Dec 21 12:27:30 2008
+++ portstools/tinderbox/webui/templates/paefchen/header.inc.tpl	Wed May  6 15:07:02 2009
@@ -28,7 +28,7 @@
 	<div id="topmenu">
 		<a id="top"></a>
 		<div class="left">
-<?php if (is_array($topmenu) && count($topmenu) > 0) { ?>
+<?php if (isset($topmenu) && is_array($topmenu) && count($topmenu) > 0) { ?>
 			<ul>
 	<?php foreach ($topmenu as $menu_title => $menu_url) { ?>
 				<li><a href="<?php echo $menu_url?>"><?php echo $menu_title?></a></li>
@@ -52,7 +52,7 @@
 <?php } ?>
 		</div>
 	</div>
-	<?php if (is_array($legend) && count($legend) > 0) { ?>
+	<?php if ( isset($legend) && is_array($legend) && count($legend) > 0) { ?>
 	<div id="legend">
 		<ul>
 			<?php foreach ($legend as $items) { ?>
