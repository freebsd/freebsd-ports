--- vendor/openssl/src/ssl/mod.rs.orig	2018-12-22 10:43:42 UTC
+++ vendor/openssl/src/ssl/mod.rs
@@ -3690,9 +3690,14 @@ cfg_if! {
 }
 
 cfg_if! {
-    if #[cfg(ossl110)] {
+    if #[cfg(any(ossl110, libressl291))] {
         use ffi::{TLS_method, DTLS_method};
-
+    } else {
+        use ffi::{SSLv23_method as TLS_method, DTLSv1_method as DTLS_method};
+    }
+}
+cfg_if! {
+    if #[cfg(ossl110)] {
         unsafe fn get_new_idx(f: ffi::CRYPTO_EX_free) -> c_int {
             ffi::CRYPTO_get_ex_new_index(
                 ffi::CRYPTO_EX_INDEX_SSL_CTX,
@@ -3715,8 +3720,6 @@ cfg_if! {
             )
         }
     } else {
-        use ffi::{SSLv23_method as TLS_method, DTLSv1_method as DTLS_method};
-
         unsafe fn get_new_idx(f: ffi::CRYPTO_EX_free) -> c_int {
             ffi::SSL_CTX_get_ex_new_index(0, ptr::null_mut(), None, None, Some(f))
         }
