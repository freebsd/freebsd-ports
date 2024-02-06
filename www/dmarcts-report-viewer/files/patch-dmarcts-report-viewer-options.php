--- dmarcts-report-viewer-options.php.orig	2023-07-15 05:56:09 UTC
+++ dmarcts-report-viewer-options.php
@@ -255,7 +255,7 @@ function create_select($option_name, $option = array()
 //####################################################################
 
 // These files must exist, in the same folder as this script.
-include "dmarcts-report-viewer-config.php";
+include "%%ETCDIR%%/%%PORTNAME%%-config.php";
 include "dmarcts-report-viewer-common.php";
 
 // Get all configuration options
