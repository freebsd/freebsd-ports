--- src/hb_wrapper.rs.orig	2023-04-25 09:08:05 UTC
+++ src/hb_wrapper.rs
@@ -6,6 +6,7 @@ use font_kit::loaders::freetype::NativeFont;
 // use harfbuzz for shaping ligatures
 pub use harfbuzz::*;
 use harfbuzz_sys as harfbuzz;
+use std::os::raw::c_char;
 use std::mem;
 
 /// font feature tag
@@ -14,7 +15,7 @@ pub fn feature_from_tag(tag: &str) -> Result<hb_featur
         let mut feature = mem::zeroed();
         ensure!(
             hb_feature_from_string(
-                tag.as_ptr() as *const i8,
+                tag.as_ptr() as *const c_char,
                 tag.len() as i32,
                 &mut feature as *mut _
             ) != 0,
@@ -88,7 +89,7 @@ impl HBBuffer {
         unsafe {
             hb_buffer_add_utf8(
                 self.buffer,
-                s.as_ptr() as *const i8,
+                s.as_ptr() as *const c_char,
                 s.len() as i32,
                 0,
                 s.len() as i32,
