--- cargo-crates/jni-0.17.0/build.rs.orig	2021-03-07 13:14:13 UTC
+++ cargo-crates/jni-0.17.0/build.rs
@@ -22,6 +22,8 @@ use std::{
 const EXPECTED_JVM_FILENAME: &str = "jvm.dll";
 #[cfg(target_os = "linux")]
 const EXPECTED_JVM_FILENAME: &str = "libjvm.so";
+#[cfg(target_os = "freebsd")]
+const EXPECTED_JVM_FILENAME: &str = "libjvm.so";
 #[cfg(target_os = "macos")]
 const EXPECTED_JVM_FILENAME: &str = "libjli.dylib";
 
