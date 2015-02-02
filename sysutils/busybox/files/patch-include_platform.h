--- include/platform.h.orig	2015-01-27 08:49:43 UTC
+++ include/platform.h
@@ -544,4 +544,10 @@ extern int vasprintf(char **string_ptr, 
 extern ssize_t getline(char **lineptr, size_t *n, FILE *stream) FAST_FUNC;
 #endif
 
+#include <string.h>
+static ALWAYS_INLINE void *mempcpy(void *dest, const void *src, size_t len)
+{
+	return memcpy(dest, src, len) + len;
+}
+
 #endif
