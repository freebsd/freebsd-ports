--- runtime/ops/signal.rs.orig	2024-10-30 14:21:47.395974000 +0100
+++ runtime/ops/signal.rs	2024-10-30 14:21:30.433974000 +0100
@@ -49,8 +49,8 @@ pub enum SignalError {
   #[cfg(any(
     target_os = "android",
     target_os = "linux",
+    target_os = "freebsd",
     target_os = "openbsd",
-    target_os = "openbsd",
     target_os = "macos",
     target_os = "solaris",
     target_os = "illumos"
@@ -60,7 +60,7 @@ pub enum SignalError {
   #[cfg(any(
     target_os = "android",
     target_os = "linux",
-    target_os = "openbsd",
+    target_os = "freebsd",
     target_os = "openbsd",
     target_os = "macos",
     target_os = "solaris",
