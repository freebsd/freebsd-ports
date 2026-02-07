--- src/quickjs-libc.c.orig	2021-03-20 11:09:33 UTC
+++ src/quickjs-libc.c
@@ -58,8 +58,11 @@ char ** environ=&ptr;
 char ** environ=&ptr;
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
+extern char **environ;
 typedef sig_t sighandler_t;
+#endif
+#if defined(__APPLE__)
 #if !defined(environ)
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
@@ -3613,6 +3616,8 @@ void js_std_set_worker_new_context_func(JSContext *(*f
 #define OS_PLATFORM "darwin"
 #elif defined(EMSCRIPTEN)
 #define OS_PLATFORM "js"
+#elif defined(__FreeBSD__)
+#define OS_PLATFORM "freebsd"
 #else
 #define OS_PLATFORM "linux"
 #endif
