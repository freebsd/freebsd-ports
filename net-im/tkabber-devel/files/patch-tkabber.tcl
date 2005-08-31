--- tkabber.tcl.orig	Mon Aug  1 01:09:36 2005
+++ tkabber.tcl	Wed Aug  3 11:35:21 2005
@@ -75,7 +75,7 @@
     return $snapshot
 }
 
-set version "0.9.8-alpha[get_snapshot [file join $rootdir ChangeLog]]"
+set version "0.9.8-alpha[get_snapshot [file join $rootdir version]]"
 set toolkit_version "Tcl/Tk [info patchlevel]"
 set debug_lvls {}
 
