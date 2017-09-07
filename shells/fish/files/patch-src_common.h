--- src/common.h.orig	2017-06-16 23:55:11 UTC
+++ src/common.h
@@ -213,23 +213,21 @@ extern bool has_working_tty_timestamps;
 /// stdio functions and should be writing the message to stderr rather than stdout. Second, if
 /// possible it is useful to provide additional context such as a stack backtrace.
 #undef assert
-#undef __assert
-//#define assert(e)  do {(void)((e) ? ((void)0) : __assert(#e, __FILE__, __LINE__)); } while(false)
-#define assert(e) (e) ? ((void)0) : __assert(#e, __FILE__, __LINE__, 0)
-#define assert_with_errno(e) (e) ? ((void)0) : __assert(#e, __FILE__, __LINE__, errno)
-#define DIE(msg) __assert(msg, __FILE__, __LINE__, 0)
-#define DIE_WITH_ERRNO(msg) __assert(msg, __FILE__, __LINE__, errno)
+#define assert(e) (e) ? ((void)0) : __fish_assert(#e, __FILE__, __LINE__, 0)
+#define assert_with_errno(e) (e) ? ((void)0) : __fish_assert(#e, __FILE__, __LINE__, errno)
+#define DIE(msg) __fish_assert(msg, __FILE__, __LINE__, 0)
+#define DIE_WITH_ERRNO(msg) __fish_assert(msg, __FILE__, __LINE__, errno)
 /// This macro is meant to be used with functions that return zero on success otherwise return an
 /// errno value. Most notably the pthread family of functions which we never expect to fail.
 #define DIE_ON_FAILURE(e)                             \
     do {                                              \
         int status = e;                               \
         if (status != 0) {                            \
-            __assert(#e, __FILE__, __LINE__, status); \
+            __fish_assert(#e, __FILE__, __LINE__, status); \
         }                                             \
     } while (0)
 
-[[noreturn]] void __assert(const char *msg, const char *file, size_t line, int error);
+[[noreturn]] void __fish_assert(const char *msg, const char *file, size_t line, int error);
 
 /// Check if signals are blocked. If so, print an error message and return from the function
 /// performing this check.
