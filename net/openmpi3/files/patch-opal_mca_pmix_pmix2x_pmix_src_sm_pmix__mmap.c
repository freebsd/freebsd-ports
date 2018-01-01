--- opal/mca/pmix/pmix2x/pmix/src/sm/pmix_mmap.c.orig	2017-12-28 19:08:34 UTC
+++ opal/mca/pmix/pmix2x/pmix/src/sm/pmix_mmap.c
@@ -66,6 +66,9 @@ int _mmap_segment_create(pmix_sm_seg_t *sm_seg, const 
     if (0 != (rc = posix_fallocate(sm_seg->seg_id, 0, size))) {
         pmix_output_verbose(2, pmix_globals.debug_output,
                 "sys call posix_fallocate(2) fail\n");
+        if (EINVAL == rc) {
+            goto ftruncate;
+        }
         if (ENOSPC == rc) {
             rc = PMIX_ERR_OUT_OF_RESOURCE;
             goto out;
@@ -85,6 +88,7 @@ int _mmap_segment_create(pmix_sm_seg_t *sm_seg, const 
         goto map_memory;
     }
 #endif
+ftruncate:
     if (0 != ftruncate(sm_seg->seg_id, size)) {
         pmix_output_verbose(2, pmix_globals.debug_output,
                 "sys call ftruncate(2) fail\n");
