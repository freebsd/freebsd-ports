--- opal/mca/pmix/pmix3x/pmix/src/mca/pshmem/mmap/pshmem_mmap.c.orig	2020-04-12 11:49:10 UTC
+++ opal/mca/pmix/pmix3x/pmix/src/mca/pshmem/mmap/pshmem_mmap.c
@@ -79,6 +79,9 @@ static int _mmap_segment_create(pmix_pshmem_seg_t *sm_
     if (0 != (rc = posix_fallocate(sm_seg->seg_id, 0, size))) {
         pmix_output_verbose(2, pmix_globals.debug_output,
                 "sys call posix_fallocate(2) fail\n");
+        if (EINVAL == rc) {
+            goto ftruncate;
+        }
         if (ENOSPC == rc) {
             rc = PMIX_ERR_OUT_OF_RESOURCE;
             goto out;
@@ -98,6 +101,7 @@ static int _mmap_segment_create(pmix_pshmem_seg_t *sm_
         goto map_memory;
     }
 #endif
+ftruncate:
     if (0 != ftruncate(sm_seg->seg_id, size)) {
         pmix_output_verbose(2, pmix_globals.debug_output,
                 "sys call ftruncate(2) fail\n");
