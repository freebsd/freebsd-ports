--- src/Port/Types.hs.orig	Fri Aug 29 21:39:21 2003
+++ src/Port/Types.hs	Tue Mar  9 11:58:33 2004
@@ -848,7 +848,7 @@
 
 fromCBitmap :: BitmapHandle -> IO Bitmap
 fromCBitmap bh
-  = do bm <- newForeignPtr bh osDeleteBitmap
+  = do bm <- newForeignPtr osDeleteBitmap bh
        return (Bitmap bm)
 foreign import ccall "&osDeleteBitmap" osDeleteBitmap :: FinalizerPtr BH
 
@@ -934,7 +934,7 @@
 
 fromCFont :: FontDef -> FontHandle -> IO Font
 fromCFont fontdef handle
-  = do fhandle <- newForeignPtr handle osDeleteFont
+  = do fhandle <- newForeignPtr osDeleteFont handle
        return (Font fhandle fontdef)
 foreign import ccall "&osDeleteFont" osDeleteFont :: FinalizerPtr FH
 
