--- cli/build.rs.orig	2022-10-26 10:26:25 UTC
+++ cli/build.rs
@@ -370,6 +370,12 @@ fn main() {
     }
   }
 
+  #[cfg(target_os = "freebsd")]
+  println!(
+    "cargo:rustc-link-arg-bin=deno=-Wl,--export-dynamic-symbol={}",
+    symbols_path.display()
+  );
+
   // To debug snapshot issues uncomment:
   // op_fetch_asset::trace_serializer();
 
