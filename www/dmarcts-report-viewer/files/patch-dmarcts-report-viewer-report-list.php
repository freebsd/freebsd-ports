--- dmarcts-report-viewer-report-list.php.orig	2023-07-15 05:56:09 UTC
+++ dmarcts-report-viewer-report-list.php
@@ -105,7 +105,7 @@ function tmpl_reportList($reports, $sort) {
 //####################################################################
 
 // These files are expected to be in the same folder as this script, and must exist.
-include "dmarcts-report-viewer-config.php";
+include "%%ETCDIR%%/%%PORTNAME%%-config.php";
 include "dmarcts-report-viewer-common.php";
 
 // Get all configuration options
