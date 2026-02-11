--- cargo-crates/mupdf-sys-0.6.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/mupdf-sys-0.6.0/build.rs
@@ -185,6 +185,7 @@ fn generate_bindings(target: &Target, path: &Path, sys
     builder = builder
         .allowlist_recursively(false)
         .allowlist_type("wchar_t")
+        .allowlist_type("___wchar_t")
         .allowlist_type("FILE")
         .opaque_type("FILE")
         .allowlist_item("max_align_t")
