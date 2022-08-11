--- cargo-crates/neon-0.9.1/src/lib.rs.orig	2021-03-15 17:51:55 UTC
+++ cargo-crates/neon-0.9.1/src/lib.rs
@@ -104,6 +104,7 @@ macro_rules! register_module {
     ($module:pat, $init:block) => {
         // Mark this function as a global constructor (like C++).
         #[allow(improper_ctypes)]
+        #[cfg_attr(target_os = "freebsd", link_section = ".ctors")]
         #[cfg_attr(target_os = "linux", link_section = ".ctors")]
         #[cfg_attr(target_os = "android", link_section = ".ctors")]
         #[cfg_attr(target_os = "macos", link_section = "__DATA,__mod_init_func")]
