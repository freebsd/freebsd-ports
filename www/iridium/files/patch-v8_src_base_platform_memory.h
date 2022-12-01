--- v8/src/base/platform/memory.h.orig	2022-12-01 10:35:46 UTC
+++ v8/src/base/platform/memory.h
@@ -19,11 +19,11 @@
 
 #if V8_OS_DARWIN
 #include <malloc/malloc.h>
-#else  // !V8_OS_DARWIN
+#elif !V8_OS_BSD  // !V8_OS_DARWIN
 #include <malloc.h>
 #endif  // !V8_OS_DARWIN
 
-#if (V8_OS_POSIX && !V8_OS_AIX) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_BSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif  // (V8_OS_POSIX && !V8_OS_AIX) || V8_OS_WIN
 
