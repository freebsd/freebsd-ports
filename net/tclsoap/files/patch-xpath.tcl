diff --git xpath.tcl xpath.tcl
index 14b0334..f33e02c 100644
--- xpath.tcl
+++ xpath.tcl
@@ -14,10 +14,9 @@
 # for more details.
 # -------------------------------------------------------------------------
 
-if { [catch {package require dom 2.0}] } {
-    if { [catch {package require dom 1.6}] } {
+namespace eval ::SOAP {variable domVersion}
+if { [catch {package require dom} ::SOAP::domVersion] || [package vcompare $::SOAP::domVersion 1.6] < 0} {
         error "require dom package greater than 1.6"
-    }
 }
 
 namespace eval SOAP::xpath {
