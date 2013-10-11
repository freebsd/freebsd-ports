--- ui/gfx/image/image_family.h.orig	2013-09-03 03:09:09.000000000 -0400
+++ ui/gfx/image/image_family.h	2013-09-12 18:02:08.000000000 -0400
@@ -27,8 +27,16 @@
 // include high-DPI representations).
 class UI_EXPORT ImageFamily {
  private:
-  // Forward declaration.
-  struct MapKey;
+  // An <aspect ratio, DIP width> pair.
+  // A 0x0 image has aspect ratio 1.0. 0xN and Nx0 images are treated as 0x0.
+  struct MapKey : std::pair<float, int> {
+    MapKey(float aspect, int width)
+        : std::pair<float, int>(aspect, width) {}
+
+    float aspect() const { return first; }
+
+    int width() const { return second; }
+  };
 
  public:
   // Type for iterating over all images in the family, in order.
@@ -127,17 +135,6 @@
   const gfx::Image* GetBest(const gfx::Size& size) const;
 
  private:
-  // An <aspect ratio, DIP width> pair.
-  // A 0x0 image has aspect ratio 1.0. 0xN and Nx0 images are treated as 0x0.
-  struct MapKey : std::pair<float, int> {
-    MapKey(float aspect, int width)
-        : std::pair<float, int>(aspect, width) {}
-
-    float aspect() const { return first; }
-
-    int width() const { return second; }
-  };
-
   // Find the closest aspect ratio in the map to |desired_aspect|.
   // Ties are broken by the thinner aspect.
   // |map_| must not be empty. |desired_aspect| must be > 0.0.

