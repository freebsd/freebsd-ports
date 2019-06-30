--- vendor/openssl-sys/src/crypto.rs.orig	2018-12-22 10:43:42 UTC
+++ vendor/openssl-sys/src/crypto.rs
@@ -15,7 +15,13 @@ cfg_if! {
     if #[cfg(ossl110)] {
         pub const CRYPTO_EX_INDEX_SSL: c_int = 0;
         pub const CRYPTO_EX_INDEX_SSL_CTX: c_int = 1;
-
+    } else if #[cfg(libressl)] {
+        pub const CRYPTO_EX_INDEX_SSL: c_int = 1;
+        pub const CRYPTO_EX_INDEX_SSL_CTX: c_int = 2;
+    }
+}
+cfg_if! {
+    if #[cfg(any(ossl110, libressl271))] {
         extern "C" {
             pub fn OpenSSL_version_num() -> c_ulong;
             pub fn OpenSSL_version(key: c_int) -> *const c_char;
@@ -64,7 +70,7 @@ pub type CRYPTO_EX_free = unsafe extern "C" fn(
     argp: *mut c_void,
 );
 extern "C" {
-    #[cfg(ossl110)]
+    #[cfg(any(ossl110, libressl))]
     pub fn CRYPTO_get_ex_new_index(
         class_index: c_int,
         argl: c_long,
