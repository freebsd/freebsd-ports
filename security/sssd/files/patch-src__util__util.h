--- src/util/util.h.orig	2020-03-17 13:31:28 UTC
+++ src/util/util.h
@@ -749,4 +749,6 @@ errno_t create_preauth_indicator(void);
 #define N_ELEMENTS(arr) (sizeof(arr) / sizeof(arr[0]))
 #endif
 
+#include "util/sss_bsd_errno.h"
+
 #endif /* __SSSD_UTIL_H__ */
