--- cargo-crates/image-0.24.1/src/codecs/openexr.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/image-0.24.1/src/codecs/openexr.rs
@@ -20,8 +20,6 @@
 //!     - meta data is lost
 //!     - dwaa/dwab compressed images not supported yet by the exr library
 //!     - (chroma) subsampling not supported yet by the exr library
-
-extern crate exr;
 use exr::prelude::*;
 
 use crate::error::{DecodingError, EncodingError, ImageFormatHint};
