--- crates/ghostty-vt/build.rs.orig	2026-10-28 00:00:00 UTC
+++ crates/ghostty-vt/build.rs
@@ -9,6 +9,8 @@
         "aarch64-unknown-linux-gnu" => "aarch64-linux-gnu",
         "x86_64-unknown-linux-musl" => "x86_64-linux-musl",
         "aarch64-unknown-linux-musl" => "aarch64-linux-musl",
+        "x86_64-unknown-freebsd" => "x86_64-freebsd",
+        "aarch64-unknown-freebsd" => "aarch64-freebsd",
         "x86_64-apple-darwin" => "x86_64-macos",
         "aarch64-apple-darwin" => "aarch64-macos",
         "aarch64-apple-ios" => "aarch64-ios",
