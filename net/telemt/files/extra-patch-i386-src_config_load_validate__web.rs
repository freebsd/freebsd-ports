--- src/config/load/validate_web.rs.orig	2026-09-02 08:19:03 UTC
+++ src/config/load/validate_web.rs
@@ -23,7 +23,7 @@ const MAX_WEB_TOMBSTONES_PER_SESSION: usize = 4096;
 const MAX_WEB_FRAME_BYTES: usize = 1024 * 1024;
 const MAX_WEB_FRAMES_PER_BODY: usize = 4096;
 const MAX_WEB_TOMBSTONES_PER_SESSION: usize = 4096;
-const MAX_WEB_MEMORY_ENVELOPE_BYTES: usize = 4 * 1024 * 1024 * 1024;
+const MAX_WEB_MEMORY_ENVELOPE_BYTES: usize = u32::MAX as usize;
 
 /// Validates WEB policy and resource bounds before building runtime state.
 pub(super) fn validate(config: &mut ProxyConfig) -> Result<()> {
