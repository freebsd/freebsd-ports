--- src/proxy/tests/direct_relay_security_tests/nofollow.rs.orig	2026-08-23 14:01:09 UTC
+++ src/proxy/tests/direct_relay_security_tests/nofollow.rs
@@ -26,8 +26,12 @@ fn unknown_dc_open_append_rejects_symlink_target_with_nofollow() {
         .expect_err("O_NOFOLLOW open must fail for symlink target");
     assert_eq!(
         err.raw_os_error(),
-        Some(libc::ELOOP),
-        "symlink target must be rejected with ELOOP when O_NOFOLLOW is applied"
+        Some(if cfg!(target_os = "freebsd") {
+            libc::EMLINK
+        } else {
+            libc::ELOOP
+        }),
+        "symlink target must be rejected with the platform O_NOFOLLOW errno"
     );
 }
 
@@ -54,8 +58,12 @@ fn unknown_dc_open_append_rejects_broken_symlink_target_with_nofollow() {
         .expect_err("O_NOFOLLOW open must fail for broken symlink target");
     assert_eq!(
         err.raw_os_error(),
-        Some(libc::ELOOP),
-        "broken symlink target must be rejected with ELOOP when O_NOFOLLOW is applied"
+        Some(if cfg!(target_os = "freebsd") {
+            libc::EMLINK
+        } else {
+            libc::ELOOP
+        }),
+        "broken symlink target must be rejected with the platform O_NOFOLLOW errno"
     );
 }
 
@@ -297,7 +305,11 @@ fn adversarial_check_then_symlink_flip_is_blocked_by_nofollow_open() {
         .expect_err("nofollow open must fail after symlink flip between check and open");
     assert_eq!(
         err.raw_os_error(),
-        Some(libc::ELOOP),
-        "symlink flip in check/open window must be neutralized by O_NOFOLLOW"
+        Some(if cfg!(target_os = "freebsd") {
+            libc::EMLINK
+        } else {
+            libc::ELOOP
+        }),
+        "symlink flip must be rejected with the platform O_NOFOLLOW errno"
     );
 }
