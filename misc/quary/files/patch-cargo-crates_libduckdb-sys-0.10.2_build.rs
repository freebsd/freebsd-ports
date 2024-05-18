--- cargo-crates/libduckdb-sys-0.10.2/build.rs.orig	2024-05-17 22:38:28 UTC
+++ cargo-crates/libduckdb-sys-0.10.2/build.rs
@@ -155,7 +155,7 @@ mod build_bundled {
         cfg.cpp(true)
             .flag_if_supported("-std=c++11")
             .flag_if_supported("-stdlib=libc++")
-            .flag_if_supported("-stdlib=libstdc++")
+            //.flag_if_supported("-stdlib=libstdc++")
             .flag_if_supported("/bigobj")
             .warnings(false)
             .flag_if_supported("-w");
