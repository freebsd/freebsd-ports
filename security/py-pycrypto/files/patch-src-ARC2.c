diff --git a/src/ARC2.c b/src/ARC2.c
index eb61713..35d9151 100644
--- src/ARC2.c
+++ src/ARC2.c
@@ -11,6 +11,7 @@
  */
 
 #include <string.h>  
+#include "Python.h"
 
 #define MODULE_NAME ARC2
 #define BLOCK_SIZE 8
@@ -144,6 +145,12 @@ block_init(block_state *self, U8 *key, int keylength)
 		197,243,219, 71,229,165,156,119, 10,166, 32,104,254,127,193,173
         };
 
+	if ((U32)keylength > sizeof(self->xkey)) {
+		PyErr_SetString(PyExc_ValueError,
+				"ARC2 key length must be less than 128 bytes");
+		return;
+	}
+
 	memcpy(self->xkey, key, keylength);
   
 	/* Phase 1: Expand input key to 128 bytes */
