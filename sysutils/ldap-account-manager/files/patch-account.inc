--- lib/account.inc.orig	2010-03-24 15:22:38.000000000 -0300
+++ lib/account.inc	2010-05-31 16:30:07.000000000 -0300
@@ -39,10 +39,10 @@
 * @return array list of shell names
 */
 function getshells() {
-	if (!isset($_SESSION['lampath'])) return array();
+	$shellPath = dirname(__FILE__) . '/../config/shells';
 	// Load shells from file
-	if (file_exists($_SESSION['lampath'] . 'config/shells')) {
-		$shells = file($_SESSION['lampath'] . 'config/shells');
+	if (file_exists($shellPath)) {
+		$shells = file($shellPath);
 		$i = 0;
 		while (count($shells) > $i) {
 			// remove whitespaces
@@ -386,6 +386,9 @@
 		case 'hostname':	
 					$pregexpr = '/^([[:alnum:]@\\.\\ \\_\\$-])+$/u';
 					break;
+		case 'hostObject':
+					$pregexpr = '/^[!]?([[:alnum:]@\\.\\ \\_\\$\\*-])+$/u';
+					break;
 		case 'usernameList':	// comma separated list of user names
 		case 'groupnameList':	// comma separated list of group names
 					$pregexpr = '/^([[:alnum:]@\\.\\ \\_-])+(,([[:alnum:]@\\.\\ \\_-])+)*$/u';
@@ -467,6 +470,7 @@
 					break;
 		case 'domainSID': // Samba domain SID
 					$pregexpr = "/^S\\-[0-9]\\-[0-9]\\-[0-9]{2,2}\\-[0-9]+\\-[0-9]+\\-[0-9]+$/";
+					break;
 		case 'ip': // IP address
 					$pregexpr = '/^[0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}$/';
 					break;
