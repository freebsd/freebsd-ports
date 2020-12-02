--- cargo-crates/servo-fontconfig-sys-4.0.9/build.rs.orig	2019-12-05 23:51:44 UTC
+++ cargo-crates/servo-fontconfig-sys-4.0.9/build.rs
@@ -17,7 +17,7 @@ fn main() {
         }
     }
 
-    assert!(Command::new("make")
+    assert!(Command::new("gmake")
         .env("MAKEFLAGS", env::var("CARGO_MAKEFLAGS").unwrap_or_default())
         .args(&["-R", "-f", "makefile.cargo"])
         .status()
