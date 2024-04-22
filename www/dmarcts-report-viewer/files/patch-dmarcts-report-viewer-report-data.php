--- dmarcts-report-viewer-report-data.php.orig	2023-07-15 05:56:09 UTC
+++ dmarcts-report-viewer-report-data.php
@@ -257,7 +257,7 @@ function formatXML($raw_xml, $reportnumber) {
 //####################################################################
 
 // These files are expected to be in the same folder as this script, and must exist.
-include "dmarcts-report-viewer-config.php";
+include "%%ETCDIR%%/%%PORTNAME%%-config.php";
 include "dmarcts-report-viewer-common.php";
 
 // Get all configuration options
