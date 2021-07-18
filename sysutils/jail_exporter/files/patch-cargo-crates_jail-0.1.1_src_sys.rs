--- cargo-crates/jail-0.1.1/src/sys.rs.orig	2021-04-16 09:14:49 UTC
+++ cargo-crates/jail-0.1.1/src/sys.rs
@@ -113,7 +113,7 @@ pub fn jail_create(
         )
     };
 
-    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut i8) }
+    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut libc::c_char) }
         .to_string_lossy()
         .to_string();
 
@@ -171,7 +171,7 @@ pub fn jail_clearpersist(jid: i32) -> Result<(), JailE
         )
     };
 
-    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut i8) }
+    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut libc::c_char) }
         .to_string_lossy()
         .to_string();
 
@@ -213,7 +213,7 @@ pub fn jail_getid(name: &str) -> Result<i32, JailError
         )
     };
 
-    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut i8) }
+    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut libc::c_char) }
         .to_string_lossy()
         .to_string();
 
@@ -248,7 +248,7 @@ pub fn jail_nextjid(lastjid: i32) -> Result<i32, JailE
         )
     };
 
-    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut i8) }
+    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut libc::c_char) }
         .to_string_lossy()
         .to_string();
 
