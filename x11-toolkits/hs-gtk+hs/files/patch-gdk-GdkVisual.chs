--- gdk/GdkVisual.chs.orig	Tue Feb 24 15:48:23 2004
+++ gdk/GdkVisual.chs	Tue Feb 24 15:48:49 2004
@@ -42,6 +42,7 @@
 import C2HS

 import Monad     (liftM)
+import IOExts	 (unsafePerformIO)

 import GList (List, mkList, listMapData, listFree)
 --FIXME: {#import GList#} (List, mkList, listMapData, listFree)
