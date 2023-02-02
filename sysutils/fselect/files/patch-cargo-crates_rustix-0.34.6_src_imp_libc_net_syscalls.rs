--- cargo-crates/rustix-0.34.6/src/imp/libc/net/syscalls.rs.orig	2023-02-02 13:18:53 UTC
+++ cargo-crates/rustix-0.34.6/src/imp/libc/net/syscalls.rs
@@ -548,11 +548,12 @@ pub(crate) mod sockopt {
                     return Err(io::Error::INVAL);
                 }
 
-                let tv_sec = timeout.as_secs().try_into();
-                #[cfg(not(all(target_arch = "x86_64", target_pointer_width = "32")))]
-                let tv_sec = tv_sec.unwrap_or(c::c_long::MAX);
-                #[cfg(all(target_arch = "x86_64", target_pointer_width = "32"))]
-                let tv_sec = tv_sec.unwrap_or(i64::MAX);
+                // Rust's musl libc bindings deprecated `time_t` while they
+                // transition to 64-bit `time_t`. What we want here is just
+                // "whatever type `timeval`'s `tv_sec` is", so we're ok using
+                // the deprecated type.
+                #[allow(deprecated)]
+                let tv_sec = timeout.as_secs().try_into().unwrap_or(c::time_t::MAX);
 
                 // `subsec_micros` rounds down, so we use `subsec_nanos` and
                 // manually round up.
