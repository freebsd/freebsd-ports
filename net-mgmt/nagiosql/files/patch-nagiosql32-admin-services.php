--- ../nagiosql/work/./nagiosql32/admin/services.php	2012-03-09 07:43:00.000000000 +0100
+++ ./nagiosql32/admin/services.php	2012-04-17 11:53:36.000000000 +0200
@@ -10,10 +10,10 @@
 // Project   : NagiosQL
 // Component : Service definition
 // Website   : http://www.nagiosql.org
-// Date      : $LastChangedDate: 2012-03-09 07:43:00 +0100 (Fri, 09 Mar 2012) $
+// Date      : $LastChangedDate: 2012-04-05 08:11:59 +0200 (Do, 05. Apr 2012) $
 // Author    : $LastChangedBy: martin $
 // Version   : 3.2.0
-// Revision  : $LastChangedRevision: 1282 $
+// Revision  : $LastChangedRevision: 1315 $
 //
 ///////////////////////////////////////////////////////////////////////////////
 //
@@ -41,7 +41,6 @@
 if ($chkSelValue1 != "") {
   	for ($i=1;$i<=8;$i++) {
 		${"chkTfArg$i"} = str_replace("!","::bang::",${"chkTfArg$i"});
-		${"chkTfArg$i"} = str_replace("\\","::back::",${"chkTfArg$i"});
 		if (${"chkTfArg$i"} != "") $chkSelValue1 .= "!".${"chkTfArg$i"};
   	}
 }
