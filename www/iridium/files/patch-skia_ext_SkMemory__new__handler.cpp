--- skia/ext/SkMemory_new_handler.cpp.orig	2018-03-20 23:05:30.000000000 +0100
+++ skia/ext/SkMemory_new_handler.cpp	2018-03-24 18:36:03.256042000 +0100
@@ -69,7 +69,7 @@
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = malloc(size);
 #else
     // It's the responsibility of the caller to check the return value.
@@ -89,7 +89,7 @@
   // TODO(b.kelemen): we should always use UncheckedCalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = calloc(1, size);
 #else
     // It's the responsibility of the caller to check the return value.
