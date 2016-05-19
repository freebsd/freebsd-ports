--- src/include/tcs_utils.h.orig	2014-04-24 18:05:44 UTC
+++ src/include/tcs_utils.h
@@ -18,6 +18,20 @@
 #include "tcs_tsp.h"
 #include "trousers_types.h"
 
+
+
+/* 
+ * XXX malloc wrapper 
+ *
+ * Linux: malloc(0) => '\0'
+ * *BSD:  malloc(0) => invalid to dereference
+ *
+ * => so wrap malloc(0) => calloc(1, 16) to create
+ * a 16Byte array containing '\0'
+ *
+ */
+#define malloc(x) ((x) == 0 ? calloc(1, 16) : calloc(1, (x)))
+
 struct key_mem_cache
 {
 	TCPA_KEY_HANDLE tpm_handle;
