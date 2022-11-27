--- htdocs/server_info.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/server_info.php
@@ -60,7 +60,7 @@ foreach ($attrs as $key => $values) {
 						printf('<td>%s</td>',$oidtext['title']);
 
 				else
-					if (strlen($value) > 0)
+					if (strlen((string) $value) > 0)
 						printf('<td><small>%s</small></td>',$value);
 
 			} else {
@@ -69,7 +69,7 @@ foreach ($attrs as $key => $values) {
 
 			print '</tr>';
 
-			if (isset($oidtext['desc']) && trim($oidtext['desc']))
+			if (isset($oidtext['desc']) && trim((string) $oidtext['desc']))
 				printf('<tr><td><small>%s</small></td></tr>',$oidtext['desc']);
 			else
 				echo '<tr><td>&nbsp;</td></tr>';
