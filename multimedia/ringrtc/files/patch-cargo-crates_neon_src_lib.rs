--- cargo-crates/neon-1.1.1/src/lib.rs.orig	2025-06-20 16:23:34 UTC
+++ cargo-crates/neon-1.1.1/src/lib.rs
@@ -1,3 +1,5 @@
+#![feature(used_with_arg)]
+
 //! The [Neon][neon] crate provides bindings for writing [Node.js addons][addons]
 //! (i.e., dynamically-loaded binary modules) with a safe and fast Rust API.
 //!
