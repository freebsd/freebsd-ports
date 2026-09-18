--- src/pdf/kittyv2/kgfx/region.rs.orig	2026-07-20 14:47:27 UTC
+++ src/pdf/kittyv2/kgfx/region.rs
@@ -159,7 +159,7 @@ impl MemoryRegion {
             libc::shm_open(
                 c_path.as_ptr(),
                 flags,
-                (libc::S_IRUSR | libc::S_IWUSR) as libc::c_uint,
+                (libc::S_IRUSR | libc::S_IWUSR) as libc::mode_t,
             )
         };
 
