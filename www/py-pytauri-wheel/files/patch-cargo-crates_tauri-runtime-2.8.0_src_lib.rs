-- Declare Runtime::new_any_thread for FreeBSD.
-- tauri-runtime-wry already implemented it for FreeBSD but the trait did not.
--- cargo-crates/tauri-runtime-2.8.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tauri-runtime-2.8.0/src/lib.rs
@@ -404,8 +404,8 @@ pub trait Runtime<T: UserEvent>: Debug + Sized + 'stat
   fn new(args: RuntimeInitArgs) -> Result<Self>;
 
   /// Creates a new webview runtime on any thread.
-  #[cfg(any(windows, target_os = "linux"))]
-  #[cfg_attr(docsrs, doc(cfg(any(windows, target_os = "linux"))))]
+  #[cfg(any(windows, target_os = "linux", target_os = "freebsd"))]
+  #[cfg_attr(docsrs, doc(cfg(any(windows, target_os = "linux", target_os = "freebsd"))))]
   fn new_any_thread(args: RuntimeInitArgs) -> Result<Self>;
 
   /// Creates an `EventLoopProxy` that can be used to dispatch user events to the main event loop.
