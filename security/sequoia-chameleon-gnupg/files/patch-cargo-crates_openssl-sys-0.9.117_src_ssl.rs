--- cargo-crates/openssl-sys-0.9.117/src/ssl.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-sys-0.9.117/src/ssl.rs
@@ -186,6 +186,8 @@ cfg_if! {
             | SSL_OP_LEGACY_SERVER_CONNECT
             | SSL_OP_TLSEXT_PADDING
             | SSL_OP_SAFARI_ECDHE_ECDSA_BUG;
+    } else if #[cfg(libressl440)] {
+        pub const SSL_OP_ALL: ssl_op_type!() = 0x0;
     } else if #[cfg(libressl)] {
         pub const SSL_OP_ALL: ssl_op_type!() = 0x4;
     } else {
