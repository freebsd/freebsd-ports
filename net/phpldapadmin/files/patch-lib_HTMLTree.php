--- lib/HTMLTree.php.orig	2021-12-12 02:35:51 UTC
+++ lib/HTMLTree.php
@@ -168,9 +168,10 @@ class HTMLTree extends Tree {
 		printf('<td class="name" colspan="%s">',$this->getDepth()+3-1);
 		printf('%s',$server->getName());
 
+		//		strftime('%H:%M',$server->inactivityTime()));
 		if (! is_null($server->inactivityTime())) {
 			$m = sprintf(_('Inactivity will log you off at %s'),
-				strftime('%H:%M',$server->inactivityTime()));
+				date('H:i',$server->inactivityTime()));
 			printf(' <img width="14" height="14" src="%s/timeout.png" title="%s" alt="%s"/>',IMGDIR,$m,'Timeout');
 		}
 		echo '</td></tr>';
@@ -361,7 +362,7 @@ class HTMLTree extends Tree {
 			$logged_in_dn_array = array();
 
 		} else {
-			$logged_in_branch = preg_replace('/,'.$server->getContainerTop($logged_in_dn).'$/','',$logged_in_dn);
+			$logged_in_branch = preg_replace('/,'.$server->getContainerTop($logged_in_dn).'$/','',is_null($logged_in_dn)? "":$logged_in_dn);
 			$logged_in_dn_array = pla_explode_dn($logged_in_branch);
 		}
 
@@ -375,7 +376,7 @@ class HTMLTree extends Tree {
 		if (! is_array($logged_in_dn_array))
 			$logged_in_dn_array = array($logged_in_dn);
 
-		if (trim($logged_in_dn)) {
+		if (trim((string) $logged_in_dn)) {
 			if ($server->dnExists($logged_in_dn))
 				foreach ($logged_in_dn_array as $rdn_piece) {
 					$href = sprintf('cmd.php?cmd=template_engine&server_id=%s&dn=%s',$server->getIndex(),rawurlencode($rdn));
