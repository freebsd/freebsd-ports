--- src/file.rs.orig	2026-09-29 13:29:21 UTC
+++ src/file.rs
@@ -2,8 +2,7 @@ use std::io::{self, Write};
 use log::debug;
 use std::fs;
 use std::io::{self, Write};
-use std::os::linux::fs::MetadataExt;
-use std::os::unix::fs::{symlink, OpenOptionsExt};
+use std::os::unix::fs::{symlink, MetadataExt, OpenOptionsExt};
 use std::path::{Path, PathBuf};
 
 /// Canonicalise `path`, checking for directory traversal outside of `base`.
@@ -79,7 +78,19 @@ pub fn link_localtime(
 
     // We should seek to avoid avoid /etc/localtime disappearing, even briefly, to avoid
     // applications being unhappy -- that's why we insist on atomic rename.
-    if localtime_tmp_path.metadata()?.st_dev() != localtime_path.metadata()?.st_dev() {
+    //
+    // Compare the links themselves rather than their targets, and fall back to the parent
+    // directory when there is no existing localtime file (FreeBSD systems on UTC have none).
+    let localtime_dev = match localtime_path.symlink_metadata() {
+        Ok(meta) => meta.dev(),
+        Err(err) if err.kind() == io::ErrorKind::NotFound => localtime_path
+            .parent()
+            .context("Refusing to link localtime in root")?
+            .metadata()?
+            .dev(),
+        Err(err) => bail!(err),
+    };
+    if localtime_tmp_path.symlink_metadata()?.dev() != localtime_dev {
         fs::remove_file(&localtime_tmp_path)?;
         bail!(
             "Cannot atomically rename, {} and {} are not on the same device",
