--- ../src/generic.tcl.orig	2008-08-31 12:38:25.000000000 +0800
+++ ../src/generic.tcl	2008-08-31 12:39:01.000000000 +0800
@@ -89,8 +89,6 @@
 proc tixAddBalloon {w class msg {initWait 500}} { 
     global tixBal
     if {$class == "Button" } {
-      bind $w <Enter> "+tkButtonEnter $w"
-      bind $w <Leave> "+tkButtonLeave $w"
       bind $w <ButtonPress> "+tixBalEnd $w"
     } else {
     if { $class == "Entry" } {
