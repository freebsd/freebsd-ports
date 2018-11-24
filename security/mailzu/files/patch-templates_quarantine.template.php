--- templates/quarantine.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/quarantine.template.php
@@ -143,7 +143,7 @@ function showMessagesTable($content_type
         				echo "<tr class=\"$class\" align=\"center\">";
 
 					echo '  <td><input type="checkbox" onclick="ColorRow(this,\'lightyellow\')" 
-						name="mail_id_array[]" value="' . $rs['mail_id'] . '_' . $rs['email'] . '"></td>';
+						name="mail_id_array[]" value="' . $rs['mail_id'] . '__' . $rs['email'] . '"></td>';
 					if ( (count($_SESSION['sessionMail']) > 1) || (Auth::isMailAdmin() && 
 					   ("Site Quarantine" == $_SESSION['sessionNav'] || "Site Pending Requests" == $_SESSION['sessionNav']))) {
 						echo '  <td>' . $to . '</td>';
