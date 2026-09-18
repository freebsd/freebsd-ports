--- src/pdf/kittyv2/kgfx/pool.rs.orig	2026-07-20 14:40:47 UTC
+++ src/pdf/kittyv2/kgfx/pool.rs
@@ -43,7 +43,7 @@ impl PoolSlot {
             libc::shm_open(
                 c_path.as_ptr(),
                 libc::O_RDWR | libc::O_CREAT,
-                (libc::S_IRUSR | libc::S_IWUSR) as libc::c_uint,
+                (libc::S_IRUSR | libc::S_IWUSR) as libc::mode_t,
             )
         };
 
