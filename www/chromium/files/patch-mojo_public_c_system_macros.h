--- mojo/public/c/system/macros.h.orig	2026-11-19 12:25:27 UTC
+++ mojo/public/c/system/macros.h
@@ -10,7 +10,11 @@
 
 #if !defined(__cplusplus)
 #include <assert.h>    // Defines static_assert() in C11.
+#if __has_include(<stdalign.h>)
 #include <stdalign.h>  // Defines alignof() in C11.
+#else
+#define alignof _Alignof
+#endif
 #endif
 
 // Assert things at compile time. (|msg| should be a valid identifier name.)
