--- Generator/types.tcl.orig	2012-09-13 17:01:08.000000000 +0200
+++ Generator/types.tcl	2012-09-13 17:01:48.000000000 +0200
@@ -1540,7 +1540,9 @@
       }
     }
     line -
-    header {} ;# please ignore.
+    header {
+	  ;# please ignore.
+	}
     default {
       warning "setVariable: unknow widget type: \"$type\""
     }
