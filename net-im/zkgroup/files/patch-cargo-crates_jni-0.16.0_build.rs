--- cargo-crates/jni-0.16.0/build.rs.orig	2020-12-23 01:49:28 UTC
+++ cargo-crates/jni-0.16.0/build.rs
@@ -20,6 +20,8 @@ use std::{
 
 #[cfg(target_os = "windows")]
 const EXPECTED_JVM_FILENAME: &str = "jvm.dll";
+#[cfg(target_os = "freebsd")]
+const EXPECTED_JVM_FILENAME: &str = "libjvm.so";
 #[cfg(target_os = "linux")]
 const EXPECTED_JVM_FILENAME: &str = "libjvm.so";
 #[cfg(target_os = "macos")]
