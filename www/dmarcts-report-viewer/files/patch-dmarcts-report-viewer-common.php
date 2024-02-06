--- dmarcts-report-viewer-common.php.orig	2023-07-15 05:56:09 UTC
+++ dmarcts-report-viewer-common.php
@@ -251,7 +251,7 @@ function main() {
 
 function main() {
 
-	include "dmarcts-report-viewer-config.php";
+	include "%%ETCDIR%%/%%PORTNAME%%-config.php";
 }
 
 // This function sets variables for the DMARC Result portion (left half-circle) in the Report List
