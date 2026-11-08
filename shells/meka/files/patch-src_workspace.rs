-- Add FreeBSD system paths to the sandbox allow-list so meka compiles
-- on FreeBSD.  Without this, SYSTEM_READ_PATHS is undefined for target_os
-- "freebsd" and the build fails in src/workspace.rs.
-- upstreamed: https://github.com/k4yt3x/meka/pull/9

--- src/workspace.rs.orig	2026-10-29 11:24:33.556472000 -0700
+++ src/workspace.rs	2026-10-29 11:24:36.176162000 -0700
@@ -484,7 +484,21 @@
     "/private/var/db",
     "/opt/homebrew",
     "/Library/Developer",
+    "/dev",
+];
+#[cfg(target_os = "freebsd")]
+pub(crate) const SYSTEM_READ_PATHS: &[&str] = &[
+    "/bin",
+    "/sbin",
+    "/usr",
+    "/lib",
+    "/libexec",
+    "/etc",
     "/dev",
+    "/proc",
+    "/var/db",
+    "/compat",
+    "/usr/local",
 ];
 #[cfg(windows)]
 pub(crate) const SYSTEM_READ_PATHS: &[&str] = &[];
