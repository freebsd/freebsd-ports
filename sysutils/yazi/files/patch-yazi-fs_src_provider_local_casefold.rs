--- yazi-fs/src/provider/local/casefold.rs.orig	2026-01-22 15:31:21 UTC
+++ yazi-fs/src/provider/local/casefold.rs
@@ -10,7 +10,7 @@ pub(super) async fn casefold(path: impl AsRef<Path>) -
 	tokio::task::spawn_blocking(move || casefold_impl(path)).await?
 }
 
-#[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd"))]
+#[cfg(any(target_os = "macos", target_os = "windows"))]
 fn casefold_impl(path: PathBuf) -> io::Result<PathBuf> {
 	let mut it = path.components();
 	let mut parts = vec![];
@@ -100,7 +100,7 @@ fn casefold_impl(path: PathBuf) -> io::Result<PathBuf>
 	}
 }
 
-#[cfg(any(target_os = "netbsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd"))]
 #[allow(irrefutable_let_patterns)]
 fn casefold_impl(path: PathBuf) -> io::Result<PathBuf> {
 	use std::{ffi::{CString, OsStr, OsString}, fs::File, os::{fd::{AsRawFd, FromRawFd}, unix::{ffi::{OsStrExt, OsStringExt}, fs::MetadataExt}}};
@@ -157,7 +157,7 @@ fn casefold_impl(path: PathBuf) -> io::Result<PathBuf>
 	}
 }
 
-#[cfg(any(target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "macos"))]
 fn final_path(path: &Path) -> io::Result<PathBuf> {
 	use std::{ffi::{CStr, CString, OsString}, os::{fd::{AsRawFd, FromRawFd, OwnedFd}, unix::ffi::{OsStrExt, OsStringExt}}};
 
@@ -221,6 +221,7 @@ fn final_path(path: &Path) -> io::Result<PathBuf> {
 #[cfg(any(
 	target_os = "linux",
 	target_os = "android",
+	target_os = "freebsd",
 	target_os = "netbsd",
 	target_os = "openbsd"
 ))]
@@ -229,6 +230,8 @@ fn try_from_fd(fd: std::os::fd::RawFd, needle: &Path) 
 
 	#[cfg(any(target_os = "linux", target_os = "android"))]
 	let cand = format!("/proc/self/fd/{fd}");
+	#[cfg(target_os = "freebsd")]
+	let cand = format!("/dev/fd/{fd}");
 	#[cfg(target_os = "netbsd")]
 	let cand = format!("/proc/curproc/fd/{fd}");
 	#[cfg(target_os = "openbsd")]
