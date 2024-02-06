--- dmarcts-report-viewer.php.orig	2023-07-15 05:56:09 UTC
+++ dmarcts-report-viewer.php
@@ -224,7 +224,7 @@ function html ($domains = array(), $orgs = array(), $p
 //####################################################################
 
 // These files must exist, in the same folder as this script.
-include "dmarcts-report-viewer-config.php";
+include "%%ETCDIR%%/%%PORTNAME%%-config.php";
 include "dmarcts-report-viewer-common.php";
 
 // Get all configuration options
