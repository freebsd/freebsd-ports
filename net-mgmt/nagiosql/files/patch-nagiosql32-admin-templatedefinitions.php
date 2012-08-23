--- ../nagiosql/work/./nagiosql32/admin/templatedefinitions.php	2012-02-27 13:01:17.000000000 +0100
+++ ./nagiosql32/admin/templatedefinitions.php	2012-04-05 08:12:08.000000000 +0200
@@ -10,10 +10,10 @@
 // Project   : NagiosQL
 // Component : Template definition list
 // Website   : http://www.nagiosql.org
-// Date      : $LastChangedDate: 2012-02-27 13:01:17 +0100 (Mon, 27 Feb 2012) $
+// Date      : $LastChangedDate: 2012-04-05 08:11:59 +0200 (Do, 05. Apr 2012) $
 // Author    : $LastChangedBy: martin $
 // Version   : 3.2.0
-// Revision  : $LastChangedRevision: 1257 $
+// Revision  : $LastChangedRevision: 1315 $
 //
 ///////////////////////////////////////////////////////////////////////////////
 //
@@ -102,8 +102,10 @@
 if ($chkMode == "add") {
   	if ($arrDefinition[1] == 1) {
     	$strSQL2 = "SELECT `template_name` FROM `tbl_".$chkPreTab."template` WHERE `id` = ".$arrDefinition[0];
+		$strSQL3 = "SELECT `active` FROM `tbl_".$chkPreTab."template` WHERE `id` = ".$arrDefinition[0];
   	} else {
     	$strSQL2 = "SELECT `name` FROM `tbl_".$chkPreTab."` WHERE `id` = ".$arrDefinition[0];
+		$strSQL3 = "SELECT `active` FROM `tbl_".$chkPreTab."` WHERE `id` = ".$arrDefinition[0];
   	}
   	if (isset($_SESSION['templatedefinition']) && is_array($_SESSION['templatedefinition'])) {
     	$intCheck = 0;
@@ -118,7 +120,7 @@
 			$arrTemp['idTable'] = $arrDefinition[1];
 			$arrTemp['idSort']  = 0;
 			$arrTemp['status'] = 0;
-			$arrTemp['active'] = 0;
+			$arrTemp['active'] = $myDBClass->getFieldData($strSQL3)+0;
 			$_SESSION['templatedefinition'][] = $arrTemp;
     	}
   	} else {
@@ -127,7 +129,7 @@
 		$arrTemp['idTable'] = $arrDefinition[1];
 		$arrTemp['idSort']  = 0;
 		$arrTemp['status'] = 0;
-		$arrTemp['active'] = 0;
+		$arrTemp['active'] = $myDBClass->getFieldData($strSQL3)+0;
 		$_SESSION['templatedefinition'][] = $arrTemp;
   	}
 }
