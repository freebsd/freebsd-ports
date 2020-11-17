diff --git src/util/util.h src/util/util.h
index 1e36bf02a..e883f322f 100644
--- src/util/util.h
+++ src/util/util.h
@@ -733,4 +733,6 @@ errno_t create_preauth_indicator(void);
 #define N_ELEMENTS(arr) (sizeof(arr) / sizeof(arr[0]))
 #endif
 
+#include "util/sss_bsd_errno.h"
+
 #endif /* __SSSD_UTIL_H__ */
