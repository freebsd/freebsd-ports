--- gdk/GdkColor.chs.orig	Wed Feb 25 10:46:59 2004
+++ gdk/GdkColor.chs	Wed Feb 25 10:41:30 2004
@@ -55,6 +55,7 @@
 import Monad  (liftM)

 import C2HS
+import IOExts (unsafePerformIO)

 {#import GdkVisual#} (Visual)

