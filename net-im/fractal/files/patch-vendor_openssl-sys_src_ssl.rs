--- vendor/openssl-sys/src/ssl.rs.orig	2018-12-22 10:43:42 UTC
+++ vendor/openssl-sys/src/ssl.rs
@@ -1032,7 +1032,7 @@ extern "C" {
 }
 
 cfg_if! {
-    if #[cfg(ossl110)] {
+    if #[cfg(any(ossl110, libressl291))] {
         extern "C" {
             pub fn TLS_method() -> *const SSL_METHOD;
 
