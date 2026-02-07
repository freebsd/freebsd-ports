--- cargo-crates/voa-config-0.1.1/src/file/loader.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/voa-config-0.1.1/src/file/loader.rs
@@ -3,7 +3,7 @@ use std::{
 use std::{
     collections::BTreeMap,
     ffi::{OsStr, OsString},
-    os::linux::fs::MetadataExt,
+    os::unix::fs::MetadataExt,
     path::{Path, PathBuf},
 };
 
@@ -150,7 +150,7 @@ fn is_masked(path: impl AsRef<Path>) -> bool {
         }
     }
 
-    if metadata.is_file() && metadata.st_size() == 0 {
+    if metadata.is_file() && metadata.size() == 0 {
         info!(
             "The config candidate {path:?} is empty (masked). Skipping all configs with the same file name: {file_name:?}"
         );
