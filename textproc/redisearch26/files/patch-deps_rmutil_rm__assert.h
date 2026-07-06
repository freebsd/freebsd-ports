--- deps/rmutil/rm_assert.h.orig	2026-05-30 23:42:51 UTC
+++ deps/rmutil/rm_assert.h
@@ -12,8 +12,8 @@
 
 #ifdef NDEBUG
 
-#define RS_LOG_ASSERT(ctx, condition, fmt, ...)    (__ASSERT_VOID_CAST (0))
-#define RS_LOG_ASSERT_STR(ctx, condition, str)     (__ASSERT_VOID_CAST (0))
+#define RS_LOG_ASSERT(condition, str)
+#define RS_LOG_ASSERT_STR(condition, str)
 
 #else
 
@@ -21,7 +21,7 @@
     if (__builtin_expect(!(condition), 0)) {                                            \
         RedisModule_Log(RSDummyContext, "warning", (fmt), __VA_ARGS__);                 \
         RedisModule_Assert(condition); /* Crashes server and create a crash report*/    \
-    } 
+    }
 
 #define RS_LOG_ASSERT(condition, str)  RS_LOG_ASSERT_FMT(condition, str "%s", "")
 
@@ -30,6 +30,6 @@
 #define RS_CHECK_FUNC(funcName, ...)                                          \
     if (funcName) {                                                           \
         funcName(__VA_ARGS__);                                                \
-    } 
+    }
 
-#endif  //__REDISEARCH_ASSERT__
\ No newline at end of file
+#endif  //__REDISEARCH_ASSERT__
