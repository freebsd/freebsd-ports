--- htdocs/monitor.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/monitor.php
@@ -48,7 +48,7 @@ foreach (array(
 	if (isset($results[$dn]['description'])) {
 		$description = implode(' ',$results[$dn]['description']);
 
-		$description = preg_replace('/"/','\'',$description);
+		$description = preg_replace('/"/','\'',is_null($description)? "":$description);
 	} else {
 		$description = '';
 	}
@@ -103,7 +103,7 @@ foreach (array(
 				else
 					$sc = $results[$key][$attr];
 
-				if (strcasecmp('supportedcontrol',$attr) == 0)
+				if (strcasecmp('supportedcontrol',(string) $attr) == 0)
 					foreach ($sc as $control) {
 						$oidtotext = support_oid_to_text($control);
 
@@ -199,7 +199,7 @@ foreach (array(
 	) as $dn ) {
 
 	$description = implode(' ',$results[$dn]['description']);
-	$description = preg_replace('/"/','\'',$description);
+	$description = preg_replace('/"/','\'',is_null($description)? "":$description);
 
 	printf('<tr class="list_item"><td class="heading" rowspan="2"><acronym title="%s">%s</acronym></td></tr>',$description,$dn);
 	echo '<tr class="list_item"><td class="value">';
