
$FreeBSD$

--- mhl/string.h.orig
+++ mhl/string.h
@@ -7,9 +7,30 @@
 #include <mhl/memory.h>
 
 #define	mhl_str_dup(str)	((str ? strdup(str) : strdup("")))
-#define mhl_str_ndup(str,len)	((str ? strndup(str,len) : strdup("")))
+#define mhl_str_ndup(str,len)	((str ? mystrndup(str,len) : strdup("")))
 #define mhl_str_len(str)	((str ? strlen(str) : 0))
 
+// XXX Implement strndup for FreeBSD.
+#ifdef __FreeBSD__
+#ifdef __cplusplus
+extern "C" {
+#endif
+static char *
+mystrndup(const char *str, int len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    memcpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+#ifdef __cplusplus
+}
+#endif
+#endif
+
 static inline char * mhl_str_dup_range(const char * s_start, const char * s_bound)
 {
     return mhl_str_ndup(s_start, s_bound - s_start);
