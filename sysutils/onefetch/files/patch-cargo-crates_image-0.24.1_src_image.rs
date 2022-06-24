--- cargo-crates/image-0.24.1/src/image.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/image-0.24.1/src/image.rs
@@ -290,7 +290,8 @@ pub enum ImageOutputFormat {
     /// An Image in TGA Format
     Tga,
 
-    #[cfg(feature = "openexr")]
+    #[cfg(feature = "exr")]
+    #[cfg(target_endian = "little")]
     /// An Image in OpenEXR Format
     OpenExr,
 
@@ -327,7 +328,8 @@ impl From<ImageFormat> for ImageOutputFormat {
             ImageFormat::Farbfeld => ImageOutputFormat::Farbfeld,
             #[cfg(feature = "tga")]
             ImageFormat::Tga => ImageOutputFormat::Tga,
-            #[cfg(feature = "openexr")]
+            #[cfg(feature = "exr")]
+            #[cfg(target_endian = "little")]
             ImageFormat::OpenExr => ImageOutputFormat::OpenExr,
             #[cfg(feature = "tiff")]
             ImageFormat::Tiff => ImageOutputFormat::Tiff,
