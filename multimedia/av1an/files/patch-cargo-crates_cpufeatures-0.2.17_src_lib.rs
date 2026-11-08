--- cargo-crates/cpufeatures-0.2.17/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/cpufeatures-0.2.17/src/lib.rs
@@ -143,13 +143,43 @@
 #[cfg(miri)]
 mod miri;
 
+// Fallback for targets without a runtime detection backend (e.g. powerpc64):
+// feature checks fall back to compile-time target features only.
+#[cfg(not(miri))]
 #[cfg(not(any(
     target_arch = "aarch64",
     target_arch = "loongarch64",
     target_arch = "x86",
     target_arch = "x86_64"
 )))]
-compile_error!("This crate works only on `aarch64`, `loongarch64`, `x86`, and `x86-64` targets.");
+#[macro_export]
+#[doc(hidden)]
+macro_rules! __unless_target_features {
+    ($($tf:tt),+ => $body:expr ) => {
+        {
+            #[cfg(not(all($(target_feature=$tf,)*)))]
+            $body
+
+            #[cfg(all($(target_feature=$tf,)*))]
+            true
+        }
+    };
+}
+
+#[cfg(not(miri))]
+#[cfg(not(any(
+    target_arch = "aarch64",
+    target_arch = "loongarch64",
+    target_arch = "x86",
+    target_arch = "x86_64"
+)))]
+#[macro_export]
+#[doc(hidden)]
+macro_rules! __detect_target_features {
+    ($($tf:tt),+) => {
+        false
+    };
+}
 
 /// Create module with CPU feature detection code.
 #[macro_export]
