-- Adapt HLS input to ffmpeg-next 9.0.0 API.
-- Replaces the custom input_with_dictionary_and_interrupt wrapper with
-- ffmpeg_next::format::input_with_interrupt_and_dictionary.
-- https://github.com/software-mansion/smelter/pull/2182

--- smelter-core/src/pipeline/hls/hls_input.rs.orig
+++ smelter-core/src/pipeline/hls/hls_input.rs
@@ -1,6 +1,5 @@
 use std::{
-    ffi::CString,
-    ptr, slice,
+    slice,
     sync::{
         Arc,
         atomic::{AtomicBool, Ordering},
@@ -11,13 +10,8 @@
 use bytes::Bytes;
 use ffmpeg_next::{
     Dictionary, Packet, Stream,
-    ffi::{
-        avformat_alloc_context, avformat_close_input, avformat_find_stream_info,
-        avformat_open_input,
-    },
-    format::context,
+    format::{context, input_with_interrupt_and_dictionary},
     media::Type,
-    util::interrupt,
 };
 use tracing::{Level, debug, info, span, trace, warn};
 
@@ -552,11 +546,10 @@
 
 impl FfmpegInputContext {
     fn new(url: &Arc<str>, should_close: Arc<AtomicBool>) -> Result<Self, ffmpeg_next::Error> {
-        let ctx = input_with_dictionary_and_interrupt(
-            url,
-            Dictionary::from_iter([("protocol_whitelist", "tcp,hls,http,https,file,tls")]),
-            // move is required even though types do not require it
+        let ctx = input_with_interrupt_and_dictionary(
+            &**url,
             move || should_close.load(Ordering::Relaxed),
+            Dictionary::from_iter([("protocol_whitelist", "tcp,hls,http,https,file,tls")]),
         )?;
         Ok(Self { ctx })
     }
@@ -579,43 +572,8 @@
         Ok(packet)
     }
 }
-
-/// Combined implementation of ffmpeg_next::format:input_with_interrupt and
-/// ffmpeg_next::format::input_with_dictionary that allows passing both interrupt
-/// callback and Dictionary with options
-fn input_with_dictionary_and_interrupt<F>(
-    path: &str,
-    options: Dictionary,
-    interrupt_fn: F,
-) -> Result<context::Input, ffmpeg_next::Error>
-where
-    F: FnMut() -> bool + 'static,
-{
-    unsafe {
-        let mut ps = avformat_alloc_context();
 
-        (*ps).interrupt_callback = interrupt::new(Box::new(interrupt_fn)).interrupt;
 
-        let path = CString::new(path).unwrap();
-        let mut opts = options.disown();
-        let res = avformat_open_input(&mut ps, path.as_ptr(), ptr::null_mut(), &mut opts);
-
-        Dictionary::own(opts);
-
-        match res {
-            0 => match avformat_find_stream_info(ps, ptr::null_mut()) {
-                r if r >= 0 => Ok(context::Input::wrap(ps)),
-                e => {
-                    avformat_close_input(&mut ps);
-                    Err(ffmpeg_next::Error::from(e))
-                }
-            },
-
-            e => Err(ffmpeg_next::Error::from(e)),
-        }
-    }
-}
-
 #[derive(Clone, Copy)]
 enum TrackKind {
     Audio,
