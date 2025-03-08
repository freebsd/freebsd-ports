Older FreeBSD versions return EINVAL for posix_fallocate called on ZFS

--- src/responder/nss/nsssrv_mmap_cache.c.orig	2026-01-14 15:01:42 UTC
+++ src/responder/nss/nsssrv_mmap_cache.c
@@ -19,6 +19,8 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/param.h>
+
 #include "util/util.h"
 #include "util/crypto/sss_crypto.h"
 #include "confdb/confdb.h"
@@ -1452,7 +1454,11 @@ errno_t sss_mmap_cache_init(TALLOC_CTX *mem_ctx, const
         /* Copy-on-write file systems such as ZFS and Btrfs can't
          * really support the posix_fallocate operation.
          * Fall back to ftruncate() in this case */
+#if __FreeBSD_version <= 1500000
+        if (ret == ENOSYS || ret == EOPNOTSUPP || ret == EINVAL) {
+#else
         if (ret == ENOSYS || ret == EOPNOTSUPP) {
+#endif
             ret = ftruncate(mc_ctx->fd, mc_ctx->mmap_size);
             if (ret == -1) {
                 ret = errno;
