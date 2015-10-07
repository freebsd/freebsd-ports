--- skia/ext/SkMemory_new_handler.cpp.orig	2015-08-22 15:01:57.000000000 -0400
+++ skia/ext/SkMemory_new_handler.cpp	2015-09-03 11:11:25.462063000 -0400
@@ -62,7 +62,7 @@
     // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
     // doesn't work as intended everywhere.
     void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_FREEBSD)
     result = malloc(size);
 #else
     // It's the responsibility of the caller to check the return value.
@@ -89,7 +89,7 @@
     // TODO(b.kelemen): we should always use UncheckedCalloc but currently it
     // doesn't work as intended everywhere.
     void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_FREEBSD)
     result = calloc(1, size);
 #else
     // It's the responsibility of the caller to check the return value.
