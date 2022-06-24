--- libclamav_rust/.cargo/vendor/image/src/codecs/openexr.rs.orig	2022-05-02 16:48:17 UTC
+++ libclamav_rust/.cargo/vendor/image/src/codecs/openexr.rs
@@ -20,8 +20,6 @@
 //!     - meta data is lost
 //!     - dwaa/dwab compressed images not supported yet by the exr library
 //!     - (chroma) subsampling not supported yet by the exr library
-
-extern crate exr;
 use exr::prelude::*;
 
 use crate::error::{DecodingError, EncodingError, ImageFormatHint};
