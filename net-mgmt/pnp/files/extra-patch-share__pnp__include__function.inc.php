--- share/pnp/include/function.inc.php.orig	2009-05-02 13:25:24.000000000 +0400
+++ share/pnp/include/function.inc.php	2009-07-02 19:05:07.000000000 +0400
@@ -999,6 +999,7 @@
 }
 
 function doPDF($display,$data) {
+	exit;
 	require ('fpdi.php');
 	global $NAGIOS;
 	global $conf;
@@ -1443,6 +1444,7 @@
 }
 
 function doPDFIcon($type){
+	return;
 	global $hostname;
 	global $servicedesc;
 	global $special;
