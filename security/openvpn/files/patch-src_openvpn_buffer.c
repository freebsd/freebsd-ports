--- src/openvpn/buffer.c.orig	2026-07-01 08:17:40 UTC
+++ src/openvpn/buffer.c
@@ -1376,7 +1376,10 @@ buffer_read_from_file(const char *filename, struct gc_
         return ret;
     }
 
-    const size_t size = file_stat.st_size;
+    /* for some systems, off_t is 63 bits wide + sign bit and size_t is 32 bits
+     * wide, and we need to avoid negative garbage wrapping around */
+    ASSERT(file_stat.st_size >= 0 && file_stat.st_size <= SIZE_MAX);
+    const size_t size = (size_t)file_stat.st_size;
     ret = alloc_buf_gc(size + 1, gc); /* space for trailing \0 */
     size_t read_size = fread(BPTR(&ret), 1, size, fp);
     if (read_size == 0)
