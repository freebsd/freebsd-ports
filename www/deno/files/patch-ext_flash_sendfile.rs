--- ext/flash/sendfile.rs.orig	2022-09-16 09:21:47 UTC
+++ ext/flash/sendfile.rs
@@ -15,6 +15,28 @@ impl SendFile {
 impl SendFile {
   #[inline]
   pub fn try_send(&mut self) -> Result<usize, std::io::Error> {
+    #[cfg(target_os = "freebsd")]
+    {
+      let mut bytes_sent = 0;
+      let res = unsafe {
+        libc::sendfile(
+          self.io.0,
+          self.io.1,
+          self.written as libc::off_t,
+          0,
+          std::ptr::null_mut(),
+          &mut bytes_sent,
+          0,
+        )
+      };
+      self.written += bytes_sent as usize;
+      if res == -1 {
+        Err(io::Error::last_os_error())
+      } else {
+        self.written = bytes_sent as usize;
+        Ok(res as usize)
+      }
+    }
     #[cfg(target_os = "linux")]
     {
       // This is the maximum the Linux kernel will write in a single call.
