--- cargo-crates/nix-0.23.1/src/sys/event.rs.orig	2026-04-05 23:25:02 UTC
+++ cargo-crates/nix-0.23.1/src/sys/event.rs
@@ -21,12 +21,12 @@ type type_of_udata = *mut libc::c_void;
           target_os = "ios", target_os = "macos",
           target_os = "openbsd"))]
 type type_of_udata = *mut libc::c_void;
-#[cfg(any(target_os = "dragonfly", target_os = "freebsd",
+#[cfg(any(target_os = "dragonfly",
           target_os = "ios", target_os = "macos"))]
 type type_of_data = intptr_t;
 #[cfg(any(target_os = "netbsd"))]
 type type_of_udata = intptr_t;
-#[cfg(any(target_os = "netbsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "netbsd", target_os = "freebsd", target_os = "openbsd"))]
 type type_of_data = i64;
 
 #[cfg(target_os = "netbsd")]
@@ -226,7 +226,8 @@ impl KEvent {
             flags: flags.bits(),
             fflags: fflags.bits(),
             data: data as type_of_data,
-            udata: udata as type_of_udata
+            udata: udata as type_of_udata,
+            ext: [0, 0, 0, 0],
         } }
     }
 
