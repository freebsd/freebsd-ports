--- ext/webgpu/byow.rs.orig	2024-02-10 16:18:20 UTC
+++ ext/webgpu/byow.rs
@@ -125,3 +125,30 @@ fn raw_window(
 
   Ok((win_handle, display_handle))
 }
+
+#[cfg(target_os = "freebsd")]
+fn raw_window(
+  system: &str,
+  window: *const c_void,
+  display: *const c_void,
+) -> Result<RawHandles, AnyError> {
+  if system != "x11" {
+    return Err(type_error("Invalid system on FreeBSD"));
+  }
+
+  let win_handle = {
+    let mut handle = raw_window_handle::XlibWindowHandle::empty();
+    handle.window = window as *mut c_void as _;
+
+    raw_window_handle::RawWindowHandle::Xlib(handle)
+  };
+
+  let display_handle = {
+    let mut handle = raw_window_handle::XlibDisplayHandle::empty();
+    handle.display = display as *mut c_void;
+
+    raw_window_handle::RawDisplayHandle::Xlib(handle)
+  };
+
+  Ok((win_handle, display_handle))
+}
