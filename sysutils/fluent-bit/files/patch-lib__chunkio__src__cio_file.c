--- lib/chunkio/src/cio_file.c.orig	2019-01-07 22:07:40 UTC
+++ lib/chunkio/src/cio_file.c
@@ -591,7 +591,7 @@ int cio_file_fs_size_change(struct cio_f
 
     /* macOS does not have fallocate().
      * So, we should use ftruncate always. */
-#ifndef __APPLE__
+#ifdef __linux__
     if (new_size > cf->alloc_size) {
         /*
          * To increase the file size we use fallocate() since this option
