--- tkabber.tcl.orig	Sat Mar 17 20:24:28 2007
+++ tkabber.tcl	Mon Mar 26 12:56:48 2007
@@ -104,7 +104,7 @@
     return $snapshot
 }
 
-set tkabber_version "0.9.9-SVN[get_snapshot [fullpath ChangeLog]]"
+set tkabber_version "0.9.9-SVN[get_snapshot [fullpath version]]"
 set toolkit_version "Tcl/Tk [info patchlevel]"
 
 proc rescmd {id res ls} {
