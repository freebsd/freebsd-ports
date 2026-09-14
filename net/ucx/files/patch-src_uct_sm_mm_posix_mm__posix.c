--- src/uct/sm/mm/posix/mm_posix.c.orig	2026-09-11 19:04:33 UTC
+++ src/uct/sm/mm/posix/mm_posix.c
@@ -49,6 +49,11 @@
 #define UCT_POSIX_SHM_OPEN_DIR          "/dev/shm"       /* directory path for shm_open() */
 #define UCT_POSIX_FILE_FMT              "/ucx_shm_posix_%"PRIx64
 #define UCT_POSIX_PROCFS_FILE_FMT       "/proc/%d/fd/%d" /* file pattern for procfs mode */
+#if defined(__FreeBSD__)
+#define UCT_POSIX_USE_PROC_LINK_DEFAULT "n"
+#else
+#define UCT_POSIX_USE_PROC_LINK_DEFAULT "y"
+#endif
 
 
 typedef struct uct_posix_md_config {
@@ -82,7 +87,7 @@ static ucs_config_field_t uct_posix_md_config_table[] 
      ucs_offsetof(uct_posix_md_config_t, shm_min_size),
      UCS_CONFIG_TYPE_MEMUNITS},
 
-    {"USE_PROC_LINK", "y",
+    {"USE_PROC_LINK", UCT_POSIX_USE_PROC_LINK_DEFAULT,
      "Use /proc/<pid>/fd/<fd> to share posix file.\n"
      " y   - Use /proc/<pid>/fd/<fd> to share posix file.\n"
      " n   - Use original file path to share posix file.\n",
@@ -135,18 +140,30 @@ uct_posix_md_query(uct_md_h tl_md, uct_md_attr_v2_t *m
     struct statvfs shm_statvfs;
     size_t shm_size;
 
-    if (statvfs(posix_config->dir, &shm_statvfs) < 0) {
-        ucs_error("could not stat shared memory device %s (%m)",
-                  posix_config->dir);
-        return UCS_ERR_NO_DEVICE;
+#if defined(__FreeBSD__)
+    if (uct_posix_use_shm_open(posix_config)) {
+        /*
+         * FreeBSD POSIX shared memory objects are kernel VM objects and
+         * are not backed by the filesystem mounted at /dev/shm.
+         * The actual allocation path checks whether the requested size
+         * can be backed.
+         */
+        shm_size = SIZE_MAX;
+    } else
+#endif
+    {
+        if (statvfs(posix_config->dir, &shm_statvfs) < 0) {
+            ucs_error("could not stat shared memory device %s (%m)",
+                      posix_config->dir);
+            return UCS_ERR_NO_DEVICE;
+        }
+        shm_size = shm_statvfs.f_bsize * shm_statvfs.f_bavail;
+        if (shm_size < posix_config->shm_min_size) {
+            ucs_debug("md alloc disabled: only %zu bytes left in shm", shm_size);
+            shm_size = 0;
+        }
     }
 
-    shm_size = shm_statvfs.f_bsize * shm_statvfs.f_bavail;
-    if (shm_size < posix_config->shm_min_size) {
-        ucs_debug("md alloc disabled: only %zu bytes left in shm", shm_size);
-        shm_size = 0;
-    }
-
     uct_mm_md_query(&md->super, md_attr, shm_size);
 
     md_attr->rkey_packed_size = sizeof(uct_posix_packed_rkey_t) +
@@ -200,6 +217,13 @@ static ucs_status_t uct_posix_test_mem(int shm_fd, siz
         size_to_write = ucs_min(remaining, chunk_size);
         single_write = write(shm_fd, buf, size_to_write);
 
+        if (single_write == 0) {
+            ucs_error("write returned zero before completing shared memory "
+                      "allocation");
+            status = UCS_ERR_IO_ERROR;
+            goto out_free_buf;
+        }
+
         if (single_write < 0) {
             switch(errno) {
             case ENOSPC:
@@ -551,13 +575,33 @@ uct_posix_mem_alloc(uct_md_h tl_md, size_t *length_p, 
         goto err_free_seg;
     }
 
-    /* Check if the location of the backing file has enough memory for the
-     * needed size by trying to write there before calling mmap */
-    status = uct_posix_test_mem(fd, seg->length);
-    if (status != UCS_OK) {
-        goto err_close;
+    /*
+     * Size/test the backing object before mmap.
+     *
+     * On FreeBSD, POSIX shared memory objects created by shm_open() are
+     * kernel VM objects rather than files in /dev/shm. write() does not
+     * provide the filesystem-space probing semantics used here and may
+     * return zero without making progress. Size the object explicitly
+     * with ftruncate() instead.
+     */
+#if defined(__FreeBSD__)
+    if (seg->seg_id & UCT_POSIX_SEG_FLAG_SHM_OPEN) {
+        if (ftruncate(fd, seg->length) < 0) {
+            ucs_error("ftruncate(fd=%d, length=%zu) failed: %m",
+                      fd, seg->length);
+            status = UCS_ERR_SHMEM_SEGMENT;
+            goto err_close;
+        }
+    } else
+#endif
+    {
+        /* Check if the location of the backing file has enough memory for the
+         * needed size by trying to write there before calling mmap */
+        status = uct_posix_test_mem(fd, seg->length);
+        if (status != UCS_OK) {
+            goto err_close;
+        }
     }
-
     /* If using procfs link instead of mmid, remove the original file and update
      * seg->seg_id */
     if (posix_config->use_proc_link) {
