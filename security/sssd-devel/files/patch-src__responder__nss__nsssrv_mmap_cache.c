--- src/responder/nss/nsssrv_mmap_cache.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/nss/nsssrv_mmap_cache.c
@@ -23,6 +23,7 @@
 #include "util/crypto/sss_crypto.h"
 #include "confdb/confdb.h"
 #include <sys/mman.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include "util/mmap_cache.h"
 #include "sss_client/idmap/sss_nss_idmap.h"
@@ -1402,8 +1403,14 @@ errno_t sss_mmap_cache_init(TALLOC_CTX *mem_ctx, const
     /* Attempt allocation several times, in case of EINTR */
     for (int i = 0; i < POSIX_FALLOCATE_ATTEMPTS; i++) {
         ret = posix_fallocate(mc_ctx->fd, 0, mc_ctx->mmap_size);
-        if (ret != EINTR)
-            break;
+	if (ret != EINTR && ret == EINVAL) {
+	    /* posix_fallocate doesn't work on ZFS */
+            ret = ftruncate(mc_ctx->fd, mc_ctx->mmap_size);   
+            if (ret != 0) {
+		break;
+            } 
+        } else if (ret != EINTR)
+		break;
     }
     if (ret) {
         DEBUG(SSSDBG_CRIT_FAILURE, "Failed to allocate file %s: %d(%s)\n",
