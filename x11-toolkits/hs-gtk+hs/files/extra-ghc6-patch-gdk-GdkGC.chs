--- gdk/GdkGC.chs.orig	Wed Feb 25 10:02:46 2004
+++ gdk/GdkGC.chs	Wed Feb 25 10:03:35 2004
@@ -129,10 +129,11 @@
 {#import GdkTypes#}  (Rectangle, RectanglePtr)
 import Char	     (chr)
 import IOExts	     (unsafePerformIO, IORef, newIORef, readIORef)
+import qualified Foreign.Concurrent (newForeignPtr)
 -- evil hack for C2HSDeprecated
 type ForeignObj = ForeignPtr ()
-newForeignObj = newForeignPtr
-foreignObjToAddr = foreignPtrToPtr
+newForeignObj = Foreign.Concurrent.newForeignPtr
+foreignObjToAddr = unsafeForeignPtrToPtr


 {#context lib="libgdk" prefix="gdk"#}
