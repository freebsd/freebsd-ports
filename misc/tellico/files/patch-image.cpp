--- src/image.cpp.orig	Mon Mar 15 22:39:08 2004
+++ src/image.cpp	Mon Mar 15 22:40:08 2004
@@ -21,11 +21,6 @@
 
 using Bookcase::Data::Image;
 
-inline
-bool operator== (const Image& img1, const Image& img2) {
-  return img1.id() == img2.id();
-}
-
 // I'm using the MD5 hash as the id. I consider it rather unlikely that two images in one
 // collection could ever have the same has, and this lets me do a fast comparison of two images
 // simply by comparing their ids.
