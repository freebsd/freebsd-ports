--- sigscheme/src/storage-compact.h.orig	2007-01-07 01:46:46.000000000 +0900
+++ sigscheme/src/storage-compact.h	2007-11-04 18:01:05.000000000 +0900
@@ -639,11 +639,14 @@
     (SCM_ASSERT(SCM_ALIGNED_SYMBOL_NAME(n)),                                 \
      SCM_SET_Y(SCM_SYMBOL_PTR(o), (scm_uintobj_t)(n) | SCM_MTAG_SYMBOL))
 #define SCM_ISAL_SYMBOL_INIT(o, n, c)                                        \
-    (SCM_ASSERT(SCM_ALIGNED_SYMBOL_NAME(n)),                                 \
-     SCM_INIT((o),                                                           \
-              (c),                                                           \
-              (scm_uintobj_t)(n) | SCM_MTAG_SYMBOL,                          \
-              SCM_PTAG_MISC))
+    do {                                                                     \
+        char *_s = scm_align_str(n);                                         \
+        (SCM_ASSERT(SCM_ALIGNED_SYMBOL_NAME(_s)),                            \
+         SCM_INIT((o),                                                       \
+                  (c),                                                       \
+                  (scm_uintobj_t)(_s) | SCM_MTAG_SYMBOL,                     \
+                  SCM_PTAG_MISC));                                           \
+    } while (0)
 #define SCM_CELL_SYMBOLP(c)            SCM_MISC_CELL_TYPEP((c), SYMBOL)
 #define SCM_CELL_SYMBOL_FIN(c)                                               \
     do {                                                                     \
