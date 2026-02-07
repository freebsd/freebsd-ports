--- library/init.tcl.orig	2013-10-30 14:24:31.000000000 +0100
+++ library/init.tcl	2013-10-30 14:25:34.000000000 +0100
@@ -8,7 +8,8 @@
         }
     }
 
-   initializeLibrary
-    
+   if {[info command tk] eq {tk}} {
+      initializeLibrary
+   }
 }
 
