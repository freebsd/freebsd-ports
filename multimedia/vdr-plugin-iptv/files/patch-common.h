--- a/common.h
+++ b/common.h
@@ -36,6 +36,7 @@
 
 #define SECTION_FILTER_TABLE_SIZE       7
 
+#ifndef __FreeBSD__
 #define ERROR_IF_FUNC(exp, errstr, func, ret) \
   do {                                                            \
      if (exp) {                                                   \
@@ -45,6 +46,18 @@
         ret;                                                      \
         }                                                         \
   } while (0)
+#else
+#define ERROR_IF_FUNC(exp, errstr, func, ret) \
+  do {                                                            \
+     if (exp) {                                                   \
+        char tmp[64];                                             \
+        strerror_r(errno, tmp, sizeof(tmp));                      \
+        error(errstr": %s", tmp); \
+        func;                                                     \
+        ret;                                                      \
+        }                                                         \
+  } while (0)
+#endif
 
 
 #define ERROR_IF_RET(exp, errstr, ret) ERROR_IF_FUNC(exp, errstr, ,ret);
