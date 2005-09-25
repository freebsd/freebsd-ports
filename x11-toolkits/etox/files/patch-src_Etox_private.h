--- src/Etox_private.h.orig	Mon May 24 09:34:45 2004
+++ src/Etox_private.h	Sun Sep 25 11:00:18 2005
@@ -6,6 +6,28 @@
 #include <Edb.h>
 #include "style/Etox_Style.h"
 
+#include <stdlib.h>
+#include <stdio.h>
+#include <string.h>
+#include <limits.h>
+
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
 typedef enum _etox_flags Etox_Flags;
 enum _etox_flags
 {
