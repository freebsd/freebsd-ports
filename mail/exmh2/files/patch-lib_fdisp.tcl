--- lib/fdisp.tcl.orig	2017-11-09 20:42:24.000000000 -0800
+++ lib/fdisp.tcl	2021-09-06 06:49:07.808426000 -0700
@@ -254,7 +254,7 @@
 
     # Enable wheelscroll if desired
     if {$exwin(wheelEnabled)} {
-        mscroll $fdisp(canvas) 1
+        fmscroll $fdisp(canvas) 5
     }
 
     # fdisp popup color hack
