--- deps/rmutil/rm_assert.h.orig	2024-11-17 14:45:39 UTC
+++ deps/rmutil/rm_assert.h
@@ -6,8 +6,8 @@
 
 #ifdef NDEBUG
 
-#define RS_LOG_ASSERT(ctx, condition, fmt, ...)    (__ASSERT_VOID_CAST (0))
-#define RS_LOG_ASSERT_STR(ctx, condition, str)     (__ASSERT_VOID_CAST (0))
+#define RS_LOG_ASSERT(condition, str)
+#define RS_LOG_ASSERT_STR(condition, str)
 
 #else
 
@@ -15,7 +15,7 @@
     if (__builtin_expect(!(condition), 0)) {                                            \
         RedisModule_Log(RSDummyContext, "warning", (fmt), __VA_ARGS__);                 \
         RedisModule_Assert(condition); /* Crashes server and create a crash report*/    \
-    } 
+    }
 
 #define RS_LOG_ASSERT(condition, str)  RS_LOG_ASSERT_FMT(condition, str "%s", "")
 
@@ -24,6 +24,6 @@
 #define RS_CHECK_FUNC(funcName, ...)                                          \
     if (funcName) {                                                           \
         funcName(__VA_ARGS__);                                                \
-    } 
+    }
 
-#endif  //__REDISEARCH_ASSERT__
\ No newline at end of file
+#endif  //__REDISEARCH_ASSERT__
