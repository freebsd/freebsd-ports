--- aeron-client/src/main/c/util/aeron_fileutil.c.orig	2026-11-11 07:59:50 UTC
+++ aeron-client/src/main/c/util/aeron_fileutil.c
@@ -987,10 +987,20 @@ int aeron_create_file(const char *path, size_t length,
             goto error;
         }
 #elif HAVE_POSIX_FALLOCATE
-        if (0 != posix_fallocate(fd, 0, (off_t)length))
+        int alloc_result = posix_fallocate(fd, 0, (off_t)length);
+        if (0 != alloc_result)
         {
-            AERON_SET_ERR(errno, "Failed to allocate file space: %s", path);
-            goto error;
+            if (EOPNOTSUPP != alloc_result && ENOTSUP != alloc_result)
+            {
+                AERON_SET_ERR(alloc_result, "Failed to allocate file space: %s", path);
+                goto error;
+            }
+
+            if (0 != ftruncate(fd, (off_t)length))
+            {
+                AERON_SET_ERR(errno, "Failed to truncate file: %s", path);
+                goto error;
+            }
         }
 #elif HAVE_F_PREALLOCATE
         fstore_t flags = {
