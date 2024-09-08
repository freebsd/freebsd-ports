--- cargo-crates/libsui-0.3.0/lib.rs.orig	2024-09-03 16:15:45.543587000 +0200
+++ cargo-crates/libsui-0.3.0/lib.rs	2024-09-03 16:15:32.374062000 +0200
@@ -55,7 +55,7 @@ pub mod apple_codesign;
 
 pub mod apple_codesign;
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub use elf::find_section;
 #[cfg(target_os = "macos")]
 pub use macho::find_section;
@@ -737,7 +737,7 @@ impl<'a> Elf<'a> {
     }
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 mod elf {
     use std::io::Read;
     use std::io::Seek;
