--- tkabber.tcl.orig	Tue Jul 27 17:37:59 2004
+++ tkabber.tcl	Tue Aug  3 14:34:43 2004
@@ -1,6 +1,6 @@
 #!/bin/sh
 # the next line restarts using the correct interpreter \
-exec wish "$0" -name tkabber "$@"
+exec wish8.4 "$0" -name tkabber "$@"
 
 # $Id: tkabber.tcl,v 1.219 2004/07/10 20:05:04 aleksey Exp $
 
@@ -118,7 +118,7 @@
             debugmsg tkabber "closed $chan '$res'"
         }
     }
-    exit $status
+    quit $status
 }
 
 namespace eval ssj {}
