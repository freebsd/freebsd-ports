--- ../nagiosql/work/./nagiosql32/functions/config_class.php	2012-03-07 10:38:34.000000000 +0100
+++ ./nagiosql32/functions/config_class.php	2012-04-17 11:59:16.000000000 +0200
@@ -10,10 +10,10 @@
 // Project   : NagiosQL
 // Component : Configuration Class
 // Website   : http://www.nagiosql.org
-// Date      : $LastChangedDate: 2012-03-07 10:38:34 +0100 (Wed, 07 Mar 2012) $
+// Date      : $LastChangedDate: 2012-04-17 11:47:05 +0200 (Di, 17. Apr 2012) $
 // Author    : $LastChangedBy: martin $
 // Version   : 3.2.0
-// Revision  : $LastChangedRevision: 1275 $
+// Revision  : $LastChangedRevision: 1319 $
 //
 ///////////////////////////////////////////////////////////////////////////////////////////////
 //
@@ -749,13 +749,6 @@
   	//
   	///////////////////////////////////////////////////////////////////////////////////////////
 	function createConfigSingle($strTableName,$intDbId = 0,$intMode = 0) {
-		// Get write access groups
-		if (isset($_SESSION['userid'])) {
-			$strAccess   = $this->myVisClass->getAccGroups('write');
-			$strAccWhere = " AND `access_group` IN ($strAccess) ";
-		} else {
-			$strAccWhere = "";
-		}
 		// Do not create configs in common domain
 		if ($this->intDomainId == 0) {
 			$this->processClassMessage(translate('It is not possible to write config files directly from the common domain!')."::",$this->strErrorMessage);
@@ -769,9 +762,9 @@
 			$strDomainWhere = " (`config_id`=".$this->intDomainId.") ";
 		}
 		if ($intDbId == 0) {
-    		$strSQL = "SELECT * FROM `".$strTableName."` WHERE $strDomainWhere AND `active`='1' $strAccWhere ORDER BY `id`";
+    		$strSQL = "SELECT * FROM `".$strTableName."` WHERE $strDomainWhere AND `active`='1' ORDER BY `id`";
 		} else {
-    		$strSQL = "SELECT * FROM `".$strTableName."` WHERE $strDomainWhere AND `active`='1' $strAccWhere AND `id`=$intDbId";
+    		$strSQL = "SELECT * FROM `".$strTableName."` WHERE $strDomainWhere AND `active`='1' AND `id`=$intDbId";
 		}
     	$booReturn = $this->myDBClass->getDataArray($strSQL,$arrData,$intDataCount);
     	if (($booReturn != false) && ($intDataCount != 0)) {
@@ -1381,8 +1374,8 @@
 		  	if ($key == "contacts")     	$value = $this->checkTpl($value,"contacts_tploptions","tbl_host",$intDataId,$intSkip);
 		  	if ($key == "contact_groups") 	$value = $this->checkTpl($value,"contact_groups_tploptions","tbl_host",$intDataId,$intSkip);
 		  	if ($key == "use")        		$value = $this->checkTpl($value,"use_template_tploptions","tbl_host",$intDataId,$intSkip);
+			if ($key == "check_command") 	$value = str_replace("\::bang::","\!",$value);
 			if ($key == "check_command") 	$value = str_replace("::bang::","\!",$value);
-			if ($key == "check_command") 	$value = str_replace("::back::","\\\\",$value);
 		}
 		if ($strTableName == "tbl_service") {
 		  	if ($key == "use_template")   	$key = "use";
@@ -1403,8 +1396,8 @@
 		  	if ($key == "contacts")     	$value = $this->checkTpl($value,"contacts_tploptions","tbl_service",$intDataId,$intSkip);
 		  	if ($key == "contact_groups") 	$value = $this->checkTpl($value,"contact_groups_tploptions","tbl_service",$intDataId,$intSkip);
 		  	if ($key == "use")        		$value = $this->checkTpl($value,"use_template_tploptions","tbl_service",$intDataId,$intSkip);
+			if ($key == "check_command") 	$value = str_replace("\::bang::","\!",$value);
 			if ($key == "check_command") 	$value = str_replace("::bang::","\!",$value);
-			if ($key == "check_command") 	$value = str_replace("::back::","\\\\",$value);
 		}
 		if ($strTableName == "tbl_hosttemplate") {
 			if ($key == "template_name")  	$key = "name";
