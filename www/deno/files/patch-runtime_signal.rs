--- runtime/signal.rs.orig	2024-12-13 09:29:06 UTC
+++ runtime/signal.rs
@@ -8,8 +8,8 @@ pub struct InvalidSignalStrError(pub String);
 #[cfg(any(
   target_os = "android",
   target_os = "linux",
+  target_os = "freebsd",
   target_os = "openbsd",
-  target_os = "openbsd",
   target_os = "macos",
   target_os = "solaris",
   target_os = "illumos"
@@ -26,7 +26,7 @@ pub struct InvalidSignalIntError(pub libc::c_int);
 #[cfg(any(
   target_os = "android",
   target_os = "linux",
-  target_os = "openbsd",
+  target_os = "freebsd",
   target_os = "openbsd",
   target_os = "macos",
   target_os = "solaris",
