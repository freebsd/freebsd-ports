--- messagesPendingAdmin.php.orig	2007-06-14 19:00:15 UTC
+++ messagesPendingAdmin.php
@@ -36,6 +36,8 @@ $_SESSION['sessionNav'] = "Site Pending Requests";
 // Get current page number
 $requestedPage = CmnFns::getGlobalVar('page', GET);
 
+global $content_type;
+
 $db = new DBEngine();
 
 $t = new Template(translate('Site Quarantine'));
