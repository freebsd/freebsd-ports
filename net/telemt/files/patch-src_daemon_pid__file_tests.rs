--- src/daemon/pid_file/tests.rs.orig	2026-10-05 08:27:50 UTC
+++ src/daemon/pid_file/tests.rs
@@ -390,3 +390,69 @@ fn pid_file_release_keeps_lock_inode() {
     assert_eq!(fs::metadata(&lock_path).unwrap().ino(), lock_inode);
     pid_file.release().unwrap();
 }
+
+#[test]
+fn unknown_runtime_user_does_not_create_pid_artifacts() {
+    let directory = tempfile::tempdir().unwrap();
+    let path = directory.path().join("runtime").join("telemt.pid");
+    let mut pid_file = PidFile::new(&path, true);
+    let error = pid_file.acquire_for_user(Some("telemt-test-user-that-does-not-exist"))
+        .unwrap_err();
+
+    assert!(matches!(error, DaemonError::UserNotFound(_)));
+    assert!(!path.parent().unwrap().exists());
+}
+
+#[test]
+fn selected_runtime_user_can_acquire_and_release_pid_file() {
+    let directory = tempfile::tempdir().unwrap();
+    let path = directory.path().join("runtime").join("telemt.pid");
+    let user = nix::unistd::User::from_uid(nix::unistd::Uid::effective())
+        .unwrap().expect("the test user must have a passwd entry");
+    let mut pid_file = PidFile::new(&path, true);
+
+    pid_file.acquire_for_user(Some(&user.name)).unwrap();
+    assert_eq!(read_pid_file(&path, true).unwrap(), std::process::id() as i32);
+    pid_file.release().unwrap();
+    assert!(!path.exists());
+}
+
+#[test]
+#[ignore = "requires root to create directories owned by another user"]
+fn root_acquires_pid_in_runtime_user_owned_parent_chain() {
+    use nix::unistd::{Uid, chown};
+
+    assert!(Uid::effective().is_root());
+    let user = nix::unistd::User::from_name("nobody").unwrap().unwrap();
+    assert_ne!(user.uid, Uid::from_raw(0));
+    let directory = tempfile::tempdir().unwrap();
+    let nested = directory.path().join("runtime");
+    fs::create_dir(&nested).unwrap();
+    chown(directory.path(), Some(user.uid), None).unwrap();
+    chown(&nested, Some(user.uid), None).unwrap();
+    let path = nested.join("telemt.pid");
+    let mut pid_file = PidFile::new(&path, true);
+
+    assert!(pid_file.acquire().is_err());
+    assert!(!path.exists());
+    pid_file.acquire_for_user(Some(&user.name)).unwrap();
+    assert_eq!(fs::read_to_string(&path).unwrap(), format!("{}\n", std::process::id()));
+    pid_file.release().unwrap();
+    assert!(!path.exists());
+}
+
+#[test]
+fn non_root_cannot_select_foreign_runtime_uid_before_opening_pid_path() {
+    if nix::unistd::Uid::effective().is_root() {
+        return;
+    }
+    let directory = tempfile::tempdir().unwrap();
+    let path = directory.path().join("runtime").join("telemt.pid");
+    let mut pid_file = PidFile::new(&path, true);
+
+    let error = pid_file.acquire_for_user(Some("root")).unwrap_err();
+
+    assert!(matches!(error, DaemonError::PrivilegeDrop(nix::errno::Errno::EPERM)));
+    assert!(!path.parent().unwrap().exists());
+    assert!(pid_file.ownership_file_handles().into_iter().all(|file| file.is_none()));
+}
