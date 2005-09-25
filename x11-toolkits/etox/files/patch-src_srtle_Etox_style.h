--- src/style/Etox_Style.h.orig	Sun Sep 25 10:48:36 2005
+++ src/style/Etox_Style.h	Sun Sep 25 11:01:48 2005
@@ -4,6 +4,23 @@
 #include <Edb.h>
 #include <Evas.h>
 
+#define IF_FREE(ptr) if (ptr) free(ptr); ptr = NULL;
+#define FREE(ptr) free(ptr); ptr = NULL;
+
+#define CHECK_PARAM_POINTER_RETURN(sparam, param, ret) \
+     if (!(param)) \
+         { \
+            fprintf(stderr, "Fix: func: %s, param: %s\n", __FUNCTION__, sparam); \
+            return ret; \
+         }
+
+#define CHECK_PARAM_POINTER(sparam, param) \
+     if (!(param)) \
+         { \
+            fprintf(stderr, "Fix: func: %s, param: %s\n", __FUNCTION__, sparam); \
+            return; \
+         }
+
 
 #ifdef __cplusplus
 extern "C"
