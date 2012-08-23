--- ../nagiosql/work/./nagiosql32/functions/import_class.php	2012-03-07 10:38:34.000000000 +0100
+++ ./nagiosql32/functions/import_class.php	2012-04-17 11:47:08.000000000 +0200
@@ -10,10 +10,10 @@
 // Project   : NagiosQL
 // Component : Import Class
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
@@ -75,7 +75,7 @@
     	$intRemoveTmp   = 0;
     	$strFileName    = trim($strFileName);
     	$intReturn = $this->myConfigClass->getConfigData($intConfigId,"method",$intMethod);
-		if ($intReturn != 0) { $this->strErrorMessage .= translate('Unable to get configuration data:')."method::"; return(1); }
+		if ($intReturn != 0) { $this->strErrorMessage .= translate('Unable to get configuration data:')." method::"; return(1); }
     	// Read import file
 		// Local file system
 		if ($intMethod == 1) {
