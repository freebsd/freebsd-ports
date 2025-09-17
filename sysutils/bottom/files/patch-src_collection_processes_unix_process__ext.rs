--- src/collection/processes/unix/process_ext.rs.orig	2025-09-17 11:38:11 UTC
+++ src/collection/processes/unix/process_ext.rs
@@ -179,7 +179,7 @@ fn convert_process_status_to_char(status: ProcessStatu
                 _ => '?'
             }
         } else if #[cfg(target_os = "freebsd")] {
-            const fn assert_u8(val: i8) -> u8 {
+            const fn assert_u8(val: libc::c_char) -> u8 {
                 if val < 0 { panic!("there was an invalid i8 constant that is supposed to be a char") } else { val as u8 }
             }
 
