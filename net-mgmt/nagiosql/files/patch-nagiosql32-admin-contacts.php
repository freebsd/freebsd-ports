--- ../nagiosql/work/./nagiosql32/admin/contacts.php	2012-03-27 12:47:56.000000000 +0200
+++ ./nagiosql32/admin/contacts.php	2012-04-20 12:39:56.000000000 +0200
@@ -10,10 +10,10 @@
 // Project   : NagiosQL
 // Component : Contact definitions
 // Website   : http://www.nagiosql.org
-// Date      : $LastChangedDate: 2012-03-27 12:47:56 +0200 (Tue, 27 Mar 2012) $
+// Date      : $LastChangedDate: 2012-04-20 12:39:53 +0200 (Fr, 20. Apr 2012) $
 // Author    : $LastChangedBy: martin $
 // Version   : 3.2.0
-// Revision  : $LastChangedRevision: 1308 $
+// Revision  : $LastChangedRevision: 1323 $
 //
 ///////////////////////////////////////////////////////////////////////////////
 //
@@ -259,7 +259,7 @@
   	} else {
     	$conttp->setVariable("HOST_OPTION_FIELDS","chbGr1a,chbGr1b,chbGr1c,chbGr1d,chbGr1f");
     	$conttp->setVariable("SERVICE_OPTION_FIELDS","chbGr2a,chbGr2b,chbGr2c,chbGr2d,chbGr2e,chbGr2g");
-		$conttp->setVariable("VERSION_20_VALUE_MUST",",tfFriendly");
+		$conttp->setVariable("VERSION_20_VALUE_MUST",",tfValue2");
   	}
 	// Insert data from database in "modify" mode
 	if (isset($arrModifyData) && ($chkSelModify == "modify")) {
