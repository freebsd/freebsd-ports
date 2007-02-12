--- tkabber.tcl.orig	Sun Feb 11 22:34:35 2007
+++ tkabber.tcl	Mon Feb 12 14:44:44 2007
@@ -102,7 +102,7 @@
     return $snapshot
 }
 
-set tkabber_version "0.9.9-SVN[get_snapshot [file join $rootdir ChangeLog]]"
+set tkabber_version "0.9.9-SVN[get_snapshot [file join $rootdir version]]"
 set toolkit_version "Tcl/Tk [info patchlevel]"
 if {$is_a_starkit} {
     append toolkit_version " (starkit)"
