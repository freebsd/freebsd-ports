--- lib/FXAtomic.cpp.orig	2016-11-19 22:24:23 UTC
+++ lib/FXAtomic.cpp
@@ -54,7 +54,7 @@
 
 
 // New __atomic_XXX() builtins are available
-#if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)))
+#if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7))) || defined(__clang__)
 #define HAVE_BUILTIN_ATOMIC 1
 #endif
 
