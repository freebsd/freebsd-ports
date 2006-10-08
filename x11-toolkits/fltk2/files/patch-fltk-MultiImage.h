--- fltk/MultiImage.h.orig	Sun Oct  8 20:48:03 2006
+++ fltk/MultiImage.h	Sun Oct  8 20:48:18 2006
@@ -49,7 +49,7 @@ public:
   bool fills_rectangle() const;
   bool is_frame() const;
 
-  MultiImage::~MultiImage() { delete [] pairs; }
+  ~MultiImage() { delete [] pairs; }
 
   //! for MultiImage arrays construction using set() for post initialization
   MultiImage() { pairs=0; n_images = 0; } 
