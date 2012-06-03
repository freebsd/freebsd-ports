--- ./Graphics/UI/GLUT/Types.hs.orig	2009-05-02 18:14:39.000000000 +0200
+++ ./Graphics/UI/GLUT/Types.hs	2012-05-17 00:04:47.000000000 +0200
@@ -32,11 +32,10 @@
 
 -- | An opaque identifier for a top-level window or a subwindow.
 
-newtype Window = Window CInt
-   deriving ( Eq, Ord, Show )
+type Window = CInt
 
 makeWindow :: CInt -> Window
-makeWindow = Window
+makeWindow = id
 
 --------------------------------------------------------------------------------
 
