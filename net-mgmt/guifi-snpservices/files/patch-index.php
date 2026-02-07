--- ./index.php.orig	2012-05-11 16:46:51.000000000 -0500
+++ ./index.php	2014-01-27 23:43:35.000000000 -0600
@@ -5,6 +5,6 @@
  * Main call to CNML services
  */
  
 // Common Bootstrap
 if (file_exists('common/config.php'))
   include_once("common/config.php");
@@ -91,6 +93,7 @@
   echo "Available services:\n";
   $fservices = glob('services/*.php');
   
+  $services = array();
   foreach ($fservices as $fservice) 
   	$services[] .= basename($fservice,'.php');
   echo implode('|',$services);
