--- libs/core/uv_compat/tcp.rs.orig	2026-07-05 06:35:36 UTC
+++ libs/core/uv_compat/tcp.rs
@@ -922,26 +922,26 @@ unsafe fn apply_keepalive_fd(
     // Linux/Android use TCP_KEEPIDLE; the BSDs/macOS use TCP_KEEPALIVE.
     // Both take the idle time in seconds. On any other platform we leave
     // SO_KEEPALIVE on with the system default idle time (still correct).
-    #[cfg(any(target_os = "linux", target_os = "android"))]
-    let idle_opt: Option<c_int> = Some(libc::TCP_KEEPIDLE);
     #[cfg(any(
-      target_os = "macos",
-      target_os = "ios",
+      target_os = "linux",
+      target_os = "android",
       target_os = "freebsd",
       target_os = "netbsd",
       target_os = "openbsd",
       target_os = "dragonfly"
     ))]
+    let idle_opt: Option<c_int> = Some(libc::TCP_KEEPIDLE);
+    #[cfg(any(target_os = "macos", target_os = "ios"))]
     let idle_opt: Option<c_int> = Some(libc::TCP_KEEPALIVE);
     #[cfg(not(any(
       target_os = "linux",
       target_os = "android",
-      target_os = "macos",
-      target_os = "ios",
       target_os = "freebsd",
       target_os = "netbsd",
       target_os = "openbsd",
-      target_os = "dragonfly"
+      target_os = "dragonfly",
+      target_os = "macos",
+      target_os = "ios"
     )))]
     let idle_opt: Option<c_int> = None;
 
