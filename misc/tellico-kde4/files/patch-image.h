--- src/image.h.orig	Mon Mar 15 22:39:01 2004
+++ src/image.h	Mon Mar 15 22:39:59 2004
@@ -55,6 +55,8 @@
   } // end namespace
 } // end namespace
 
-bool operator== (const Bookcase::Data::Image& img1, const Bookcase::Data::Image& img2);
+inline bool operator== (const Bookcase::Data::Image& img1, const Bookcase::Data::Image& img2) {
+  return img1.id() == img2.id();
+};
 
 #endif
