Index: portstools/tinderbox/webui/templates/paefchen/footer.inc.tpl
diff -u portstools/tinderbox/webui/templates/paefchen/footer.inc.tpl:1.2.2.1 portstools/tinderbox/webui/templates/paefchen/footer.inc.tpl:1.2.2.2
--- portstools/tinderbox/webui/templates/paefchen/footer.inc.tpl:1.2.2.1	Thu Dec 18 16:06:37 2008
+++ portstools/tinderbox/webui/templates/paefchen/footer.inc.tpl	Wed May  6 15:07:02 2009
@@ -1,4 +1,9 @@
 <!-- $Paefchen: FreeBSD/tinderbox/webui/templates/paefchen/footer.inc.tpl,v 1.1 2008/01/05 12:25:17 as Exp $ //-->
+<?php
+if ( empty ( $ui_elapsed_time ) ) {
+    $ui_elapsed_time = '';
+}
+?>
 <?php echo $display_login?>
 	</div>
 	<div id="footer">
@@ -12,7 +17,7 @@
 			</ul>
 		</div>
 		<div class="right">
-<?php if (is_array($footer_legend)) { ?>
+<?php if (isset($footer_legend) && is_array($footer_legend)) { ?>
 <?php foreach($footer_legend as $css_class => $legend_title) { ?>
 				<table>
 					<tr>
