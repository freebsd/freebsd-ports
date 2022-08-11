--- cargo-crates/image-0.24.1/src/lib.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/image-0.24.1/src/lib.rs
@@ -234,7 +234,8 @@ pub mod codecs {
     pub mod ico;
     #[cfg(feature = "jpeg")]
     pub mod jpeg;
-    #[cfg(feature = "openexr")]
+    #[cfg(feature = "exr")]
+    #[cfg(target_endian = "little")]
     pub mod openexr;
     #[cfg(feature = "png")]
     pub mod png;
