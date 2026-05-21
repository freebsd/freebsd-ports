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
@@ -336,7 +337,8 @@ impl Target {
             os: env::var("CARGO_CFG_TARGET_OS")?,
             env: env::var("CARGO_CFG_TARGET_ENV")?,
 
-            features: env::var("CARGO_CFG_TARGET_FEATURE")?
+            features: env::var("CARGO_CFG_TARGET_FEATURE")
+                .unwrap_or_default()
                 .split(',')
                 .map(str::to_owned)
                 .collect(),
