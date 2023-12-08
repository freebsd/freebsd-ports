--- lib/exwin.tcl.orig	2017-11-09 20:42:24.000000000 -0800
+++ lib/exwin.tcl	2021-09-06 06:53:11.916007000 -0700
@@ -101,12 +101,26 @@
 }
 
 proc mscroll {bindtag num} {
-    bind $bindtag <Button-5> [list %W yview scroll $num units]
-    bind $bindtag <Button-4> [list %W yview scroll -$num units]
-    bind $bindtag <Shift-Button-5> [list %W yview scroll 1 units]
-    bind $bindtag <Shift-Button-4> [list %W yview scroll -1 units]
-    bind $bindtag <Control-Button-5> [list %W yview scroll 1 pages]
-    bind $bindtag <Control-Button-4> [list %W yview scroll -1 pages]
+    # Prior to tcl 8.7a5:
+    # bind $bindtag <Button-5> [list %W yview scroll $num units]
+    # bind $bindtag <Button-4> [list %W yview scroll -$num units]
+    # bind $bindtag <Shift-Button-5> [list %W yview scroll 1 units]
+    # bind $bindtag <Shift-Button-4> [list %W yview scroll -1 units]
+    # bind $bindtag <Control-Button-5> [list %W yview scroll 1 pages]
+    # bind $bindtag <Control-Button-4> [list %W yview scroll -1 pages]
+
+    # tcl 8.7a5 and later. See
+    # https://core.tcl-lang.org/tips/doc/trunk/tip/474.md for more info:
+    bind $bindtag <MouseWheel> [ list tk::MouseWheel %W y %D [ expr 10/-$num ] pixels ]
+    bind $bindtag <Shift-MouseWheel> { tk::MouseWheel %W y %D -10 pixels }
+    bind $bindtag <Control-MouseWheel> { tk::MouseWheel %W y %D -1 pixels }
+}
+
+
+proc fmscroll {bindtag num} {
+    bind $bindtag <MouseWheel> [ list tk::MouseWheel %W y %D [ expr 200/-$num ] units ]
+    bind $bindtag <Shift-MouseWheel> { tk::MouseWheel %W y %D [expr 200/-10 ] units }
+    bind $bindtag <Control-MouseWheel> { tk::MouseWheel %W y %D -1 units }
 }
 
 
