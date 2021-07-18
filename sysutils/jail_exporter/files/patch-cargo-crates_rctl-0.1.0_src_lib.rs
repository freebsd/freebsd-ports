--- cargo-crates/rctl-0.1.0/src/lib.rs.orig	2021-04-16 09:16:09 UTC
+++ cargo-crates/rctl-0.1.0/src/lib.rs
@@ -1825,7 +1825,7 @@ fn rctl_api_wrapper<S: Into<String>>(
 
     loop {
         // Unsafe C call to get the jail resource usage.
-        if unsafe { api(inbuf.as_ptr(), inputlen, outbuf.as_mut_ptr(), outbuf.len()) } != 0 {
+        if unsafe { api(inbuf.as_ptr(), inputlen, outbuf.as_mut_ptr() as *mut libc::c_char, outbuf.len()) } != 0 {
             let err = io::Error::last_os_error();
 
             match err.raw_os_error() {
@@ -1850,7 +1850,7 @@ fn rctl_api_wrapper<S: Into<String>>(
 
         // If everything went well, convert the return C string in the outbuf
         // back into an easily usable Rust string and return.
-        break Ok(unsafe { CStr::from_ptr(outbuf.as_ptr() as *mut i8) }
+        break Ok(unsafe { CStr::from_ptr(outbuf.as_ptr() as *mut libc::c_char) }
             .to_string_lossy()
             .into());
     }
