
$FreeBSD$

--- html/alerting.php.orig
+++ html/alerting.php
@@ -449,6 +449,7 @@
 		foreach ( $alert_condition_plugin as $plugin) {
 			$selected = $alert['condition'][0] == $plugin ? 'selected' : '';
 			print "	<option value='$i' $selected>" . $plugin . "</option>\n";
+			$i++;
 		}
 	}
 ?>
