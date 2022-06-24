--- libclamav_rust/.cargo/vendor/image/src/lib.rs.orig	2022-05-02 16:48:17 UTC
+++ libclamav_rust/.cargo/vendor/image/src/lib.rs
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
