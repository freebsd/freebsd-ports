--- cargo-crates/jail-0.1.1/src/param.rs.orig	2021-04-16 09:13:39 UTC
+++ cargo-crates/jail-0.1.1/src/param.rs
@@ -640,7 +640,7 @@ pub fn get(jid: i32, name: &str) -> Result<Value, Jail
         )
     };
 
-    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut i8) }
+    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut libc::c_char) }
         .to_string_lossy()
         .to_string();
 
@@ -676,7 +676,7 @@ pub fn get(jid: i32, name: &str) -> Result<Value, Jail
         Type::S32 => Ok(Value::S32(LittleEndian::read_i32(&value))),
         Type::U32 => Ok(Value::U32(LittleEndian::read_u32(&value))),
         Type::String => Ok(Value::String({
-            unsafe { CStr::from_ptr(value.as_ptr() as *mut i8) }
+            unsafe { CStr::from_ptr(value.as_ptr() as *mut libc::c_char) }
                 .to_string_lossy()
                 .into_owned()
         })),
@@ -807,7 +807,7 @@ pub fn set(jid: i32, name: &str, value: Value) -> Resu
         )
     };
 
-    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut i8) }
+    let err = unsafe { CStr::from_ptr(errmsg.as_ptr() as *mut libc::c_char) }
         .to_string_lossy()
         .to_string();
 
