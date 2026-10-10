--- codex-rs/tui/src/clipboard_copy.rs.orig	2026-10-08 16:56:07 UTC
+++ codex-rs/tui/src/clipboard_copy.rs
@@ -8,7 +8,7 @@
 //! suppress native copying. Both the host and attached client's clipboards may
 //! change. Outside tmux and SSH, use OSC 52 only if native copying fails.
 //!
-//! On Linux, X11 and some Wayland compositors require the process that wrote the
+//! On Linux and FreeBSD, X11 and some Wayland compositors require the process that wrote the
 //! clipboard to keep its handle open. `ClipboardLease` wraps the `arboard::Clipboard`
 //! so the copy worker can retain it for the lifetime of the TUI. On other platforms the lease
 //! is always `None`.
@@ -127,19 +127,19 @@ fn copy_to_clipboard(
 
 /// Keeps a platform clipboard owner alive when the backend requires one.
 ///
-/// On Linux/X11 and some Wayland compositors, clipboard contents are served by the
+/// On Linux/FreeBSD X11 and some Wayland compositors, clipboard contents are served by the
 /// owning process. Dropping the `arboard::Clipboard` before the user pastes causes
 /// the content to vanish. Store this lease on a session-lived owner so closing a
-/// transient overlay does not release the clipboard contents. On non-Linux native paths and OSC 52
+/// transient overlay does not release the clipboard contents. On other native paths and OSC 52
 /// paths the lease is `None` — those backends do not require process-lifetime
 /// ownership.
 pub(crate) struct ClipboardLease {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     _clipboard: Option<arboard::Clipboard>,
 }
 
 impl ClipboardLease {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     fn native_linux(clipboard: arboard::Clipboard) -> Self {
         Self {
             _clipboard: Some(clipboard),
@@ -149,7 +149,7 @@ impl ClipboardLease {
     #[cfg(test)]
     pub(crate) fn test() -> Self {
         Self {
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
             _clipboard: None,
         }
     }
@@ -263,12 +263,12 @@ fn arboard_copy(
         None => clipboard.set_text(text),
     }
     .map_err(|e| format!("failed to set clipboard text: {e}"))?;
-    // Linux clipboard owners must stay alive until the user pastes.
-    #[cfg(target_os = "linux")]
+    // X11 clipboard owners must stay alive until the user pastes.
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     {
         Ok(Some(ClipboardLease::native_linux(clipboard)))
     }
-    #[cfg(not(target_os = "linux"))]
+    #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
     {
         Ok(None)
     }
