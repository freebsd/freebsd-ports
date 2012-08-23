--- ../nagiosql/work/./nagiosql32/functions/prepend_content.php	2012-02-29 11:01:14.000000000 +0100
+++ ./nagiosql32/functions/prepend_content.php	2012-04-04 07:30:16.000000000 +0200
@@ -178,6 +178,14 @@
 	$chkTfValue19   = addslashes($chkTfValue19);
 	$chkTfValue20   = addslashes($chkTfValue20);
 	$chkTaValue1    = addslashes($chkTaValue1);
+	$chkTfArg1		= addslashes($chkTfArg1);	
+	$chkTfArg2		= addslashes($chkTfArg2);
+	$chkTfArg3		= addslashes($chkTfArg3);
+	$chkTfArg4		= addslashes($chkTfArg4);
+	$chkTfArg5		= addslashes($chkTfArg5);
+	$chkTfArg6		= addslashes($chkTfArg6);
+	$chkTfArg7		= addslashes($chkTfArg7);
+	$chkTfArg8		= addslashes($chkTfArg8);
 	$chkTaFileText  = addslashes($chkTaFileText);
 }
 //
@@ -204,6 +212,14 @@
 $chkTfValue18   = $myVisClass->tfSecure($chkTfValue18);
 $chkTfValue19   = $myVisClass->tfSecure($chkTfValue19);
 $chkTfValue20   = $myVisClass->tfSecure($chkTfValue20);
+$chkTfArg1		= $myVisClass->tfSecure($chkTfArg1);	
+$chkTfArg2		= $myVisClass->tfSecure($chkTfArg2);
+$chkTfArg3		= $myVisClass->tfSecure($chkTfArg3);
+$chkTfArg4		= $myVisClass->tfSecure($chkTfArg4);
+$chkTfArg5		= $myVisClass->tfSecure($chkTfArg5);
+$chkTfArg6		= $myVisClass->tfSecure($chkTfArg6);
+$chkTfArg7		= $myVisClass->tfSecure($chkTfArg7);
+$chkTfArg8		= $myVisClass->tfSecure($chkTfArg8);
 $chkTaValue1    = $myVisClass->tfSecure($chkTaValue1);
 $chkTaFileText  = stripslashes($chkTaFileText);
 //
