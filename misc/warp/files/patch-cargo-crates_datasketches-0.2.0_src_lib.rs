--- cargo-crates/datasketches-0.2.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/datasketches-0.2.0/src/lib.rs
@@ -26,10 +26,6 @@
 #![cfg_attr(docsrs, feature(doc_cfg))]
 #![deny(missing_docs)]
 
-// See https://github.com/apache/datasketches-rust/issues/28 for more information.
-#[cfg(target_endian = "big")]
-compile_error!("datasketches does not support big-endian targets");
-
 pub mod bloom;
 pub mod common;
 pub mod countmin;
