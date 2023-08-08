--- synapse/media/thumbnailer.py.orig  2023-07-11 08:10:15 UTC
+++ synapse/media/thumbnailer.py
@@ -131,7 +131,7 @@ class Thumbnailer:
             else:
                 with self.image:
                     self.image = self.image.convert("RGB")
-        return self.image.resize((width, height), Image.ANTIALIAS)
+        return self.image.resize((width, height), Image.LANCZOS)
 
     def scale(self, width: int, height: int, output_type: str) -> BytesIO:
         """Rescales the image to the given dimensions.
