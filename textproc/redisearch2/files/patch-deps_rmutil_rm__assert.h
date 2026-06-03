--- deps/rmutil/rm_assert.h.orig	2026-05-31 00:27:00 UTC
+++ deps/rmutil/rm_assert.h
@@ -12,8 +12,8 @@
 
 #ifdef NDEBUG
 
-#define RS_LOG_ASSERT(ctx, condition, fmt, ...)    (__ASSERT_VOID_CAST (0))
-#define RS_LOG_ASSERT_STR(ctx, condition, str)     (__ASSERT_VOID_CAST (0))
+#define RS_LOG_ASSERT(condition, str)
+#define RS_LOG_ASSERT_STR(condition, str)
 
 #else
 
@@ -32,4 +32,4 @@
         funcName(__VA_ARGS__);                                                \
     } 
 
-#endif  //__REDISEARCH_ASSERT__
\ No newline at end of file
+#endif  //__REDISEARCH_ASSERT__
