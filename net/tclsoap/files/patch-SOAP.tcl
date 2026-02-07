diff --git SOAP.tcl SOAP.tcl
index 4ba871e..1aaa071 100644
--- SOAP.tcl
+++ SOAP.tcl
@@ -22,12 +22,11 @@ package require rpcvar;                 # TclSOAP
 
 namespace eval ::SOAP {variable domVersion}
 if {[catch {package require SOAP::dom 1.0} ::SOAP::domVersion]} {
-    if { [catch {package require dom 2.0} ::SOAP::domVersion]} {
-        if { [catch {package require dom 1.6} ::SOAP::domVersion]} {
-            error "require dom package greater than 1.6"
-        }
-        package require SOAP::xpath;    # TclSOAP
+    if {[catch {package require dom} ::SOAP::domVersion] || [package vcompare $::SOAP::domVersion 1.6] < 0} {
+        error "require dom package greater than 1.6"
     }
+    package require SOAP::xpath;    # TclSOAP
+
     proc ::SOAP::createDocument {name} {
         set doc [dom::DOMImplementation create]
         return [dom::document createElement $doc $name]
