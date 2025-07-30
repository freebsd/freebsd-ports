--- main.c.orig	2025-07-30 19:54:07 UTC
+++ main.c
@@ -302,7 +302,11 @@ openat_retry(const int dfd, const char *const path, in
 	if (fd >= 0 || errno != EINTR) {
 		return fd;
 	} else {
+#ifdef __powerpc__
+		return openat_retry(dfd, path, flags, mode);
+#else
 		__attribute__((musttail)) return openat_retry(dfd, path, flags, mode);
+#endif
 	}
 }
 
