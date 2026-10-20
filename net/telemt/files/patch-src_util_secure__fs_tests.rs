--- src/util/secure_fs/tests.rs.orig	2026-10-05 08:27:50 UTC
+++ src/util/secure_fs/tests.rs
@@ -121,3 +121,43 @@ fn anchored_replace_survives_parent_path_substitution(
         .mode();
     assert_eq!(mode & 0o777, 0o600);
 }
+
+#[test]
+fn runtime_uid_controls_trust_for_the_entire_parent_chain() {
+    let directory = tempfile::tempdir().unwrap();
+    let nested = directory.path().join("runtime");
+    std::fs::create_dir(&nested).unwrap();
+    let uid = nix::unistd::Uid::effective().as_raw();
+    let path = nested.join("telemt.pid");
+
+    assert!(AnchoredPath::open_trusted_parent_or_create(&path, 0o755, uid).is_ok());
+    // Root-owned components remain trusted independently of the runtime UID.
+    assert!(AnchoredPath::open_trusted_parent_or_create(
+        std::path::Path::new("/telemt-trust-test.pid"), 0o755, uid,
+    ).is_ok());
+    if uid != 0 {
+        let error = AnchoredPath::open_trusted_parent_or_create(&path, 0o755, 0)
+            .err().expect("an unselected non-root owner must be rejected");
+        assert_eq!(error.kind(), std::io::ErrorKind::PermissionDenied);
+    }
+}
+
+#[test]
+fn runtime_uid_does_not_bypass_permissions_or_symlink_checks() {
+    let directory = tempfile::tempdir().unwrap();
+    let nested = directory.path().join("runtime");
+    std::fs::create_dir(&nested).unwrap();
+    let uid = nix::unistd::Uid::effective().as_raw();
+    for mode in [0o775, 0o757, 0o1777] {
+        std::fs::set_permissions(&nested, std::fs::Permissions::from_mode(mode)).unwrap();
+        assert!(AnchoredPath::open_trusted_parent_or_create(
+            &nested.join("telemt.pid"), 0o755, uid,
+        ).is_err());
+    }
+    std::fs::set_permissions(&nested, std::fs::Permissions::from_mode(0o755)).unwrap();
+    let link = directory.path().join("link");
+    symlink(&nested, &link).unwrap();
+    assert!(AnchoredPath::open_trusted_parent_or_create(
+        &link.join("telemt.pid"), 0o755, uid,
+    ).is_err());
+}
