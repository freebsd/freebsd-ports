--- cargo-crates/parity-util-mem-0.7.0/src/allocators.rs.orig	2021-05-09 06:13:15 UTC
+++ cargo-crates/parity-util-mem-0.7.0/src/allocators.rs
@@ -97,7 +97,7 @@ mod usable_size {
 				libmimalloc_sys::mi_usable_size(ptr as *mut _)
 			}
 
-		} else if #[cfg(any(target_os = "linux", target_os = "android"))] {
+		} else if #[cfg(unix)] {
 
 			/// Linux call system allocator (currently malloc).
 			extern "C" {
