--- src/proxy/tests/direct_relay_security_tests/anchored.rs.orig	2026-09-28 20:30:20 UTC
+++ src/proxy/tests/direct_relay_security_tests/anchored.rs
@@ -62,7 +62,7 @@ fn adversarial_parent_swap_after_check_is_blocked_by_a
     assert!(
         matches!(
             raw,
-            Some(libc::ELOOP) | Some(libc::ENOTDIR) | Some(libc::ENOENT)
+            Some(libc::ELOOP) | Some(libc::EMLINK) | Some(libc::ENOTDIR) | Some(libc::ENOENT)
         ),
         "anchored open must fail closed on parent swap race, got raw_os_error={raw:?}"
     );
@@ -102,11 +102,12 @@ fn adversarial_intermediate_parent_swap_is_blocked_by_
     let err = open_unknown_dc_log_append_anchored(&sanitized)
         .expect_err("anchored open must reject a swapped intermediate component");
     let raw = err.raw_os_error();
+    // FreeBSD reports EMLINK when O_NOFOLLOW rejects a symbolic link.
     assert!(
         matches!(
             raw,
             Some(libc::ELOOP) | Some(libc::ENOTDIR) | Some(libc::ENOENT)
-        ),
+        ) || (cfg!(target_os = "freebsd") && raw == Some(libc::EMLINK)),
         "component walk must fail closed on intermediate swap, got raw_os_error={raw:?}"
     );
     assert!(
@@ -286,8 +287,12 @@ fn anchored_open_rejects_existing_symlink_target() {
         .expect_err("anchored open must reject symlinked filename target");
     assert_eq!(
         err.raw_os_error(),
-        Some(libc::ELOOP),
-        "anchored open should fail closed with ELOOP on symlinked target"
+        Some(if cfg!(target_os = "freebsd") {
+            libc::EMLINK
+        } else {
+            libc::ELOOP
+        }),
+        "anchored open must reject a symlink with the platform O_NOFOLLOW errno"
     );
 }
 
