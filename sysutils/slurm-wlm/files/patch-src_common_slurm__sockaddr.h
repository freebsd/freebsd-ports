--- src/common/slurm_sockaddr.h.orig	2026-01-29 00:01:06 UTC
+++ src/common/slurm_sockaddr.h
@@ -0,0 +1,26 @@
+#pragma once
+
+#include <sys/types.h>
+#include <sys/socket.h>
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+/* Fix length fields (sin_len/sin6_len/sun_len/sa_len when present) and
+ * return the correct socklen_t to pass to bind/connect/getnameinfo.
+ *
+ * - If sa is mutable, you can call this directly.
+ * - If sa is const, use slurm_sockaddr_copy_fix() to copy into a mutable buffer.
+ */
+socklen_t slurm_sockaddr_fixlen(struct sockaddr *sa, socklen_t provided_len);
+
+/* Copy src->dst and then apply slurm_sockaddr_fixlen() on dst. */
+int slurm_sockaddr_copy_fix(struct sockaddr_storage *dst,
+			    const struct sockaddr *src,
+			    socklen_t src_len,
+			    socklen_t *out_len);
+
+#ifdef __cplusplus
+}
+#endif
