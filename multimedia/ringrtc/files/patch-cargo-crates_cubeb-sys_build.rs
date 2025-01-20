--- cargo-crates/cubeb-sys-0.18.0/build.rs.orig	2024-11-18 16:08:09.330015000 +0100
+++ cargo-crates/cubeb-sys-0.18.0/build.rs	2024-11-18 16:01:50.423150000 +0100
@@ -33,7 +33,6 @@ fn main() {
         return;
     }
 
-    let _ = fs::remove_dir_all(env::var("OUT_DIR").unwrap());
     t!(fs::create_dir_all(env::var("OUT_DIR").unwrap()));
 
     env::remove_var("DESTDIR");
@@ -51,14 +50,14 @@ fn main() {
         // so we expected a vendored copy of the source to be available.
         // Vendored copy generated with:
         // "tar -c -f libcubeb_vendored.tar --exclude libcubeb/googletest libcubeb"
-        t!(Command::new("tar")
-            .args([
-                "xvfC",
-                "libcubeb_vendored.tar",
-                &env::var("OUT_DIR").unwrap(),
-            ])
-            .status());
-        env::var("OUT_DIR").unwrap() + "/libcubeb"
+//        t!(Command::new("tar")
+//            .args([
+//                "xvfC",
+//                "libcubeb_vendored.tar",
+//                &env::var("OUT_DIR").unwrap(),
+//            ])
+//            .status());
+        "WRKDIR/libcubeb".to_owned()
     };
 
     let target = env::var("TARGET").unwrap();
@@ -144,23 +143,23 @@ fn main() {
         // Ignore the result of find_library. We don't care if the
         // libraries are missing.
         let _ = pkg_config::find_library("alsa");
-        if pkg_config::find_library("libpulse").is_ok() {
-            // Do not link the rust backends for tests: doing so causes duplicate
-            // symbol definitions.
-            #[cfg(not(feature = "unittest-build"))]
-            {
-                println!("cargo:rustc-link-lib=static=cubeb_pulse");
-                let mut search_path = std::env::current_dir().unwrap();
-                search_path.push(&(libcubeb_path + "/src/cubeb-pulse-rs/target"));
-                search_path.push(&target);
-                if debug {
-                    search_path.push("debug");
-                } else {
-                    search_path.push("release");
-                }
-                println!("cargo:rustc-link-search=native={}", search_path.display());
-            }
-        }
+//        if pkg_config::find_library("libpulse").is_ok() {
+//            // Do not link the rust backends for tests: doing so causes duplicate
+//            // symbol definitions.
+//            #[cfg(not(feature = "unittest-build"))]
+//            {
+//                println!("cargo:rustc-link-lib=static=cubeb_pulse");
+//                let mut search_path = std::env::current_dir().unwrap();
+//                search_path.push(&(libcubeb_path + "/src/cubeb-pulse-rs/target"));
+//                search_path.push(&target);
+//                if debug {
+//                    search_path.push("debug");
+//                } else {
+//                    search_path.push("release");
+//                }
+//                println!("cargo:rustc-link-search=native={}", search_path.display());
+//            }
+//        }
         let _ = pkg_config::find_library("jack");
         let _ = pkg_config::find_library("speexdsp");
         if android {
