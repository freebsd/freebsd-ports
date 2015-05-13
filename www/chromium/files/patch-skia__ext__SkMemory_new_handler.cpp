--- skia/ext/SkMemory_new_handler.cpp.orig	2015-04-20 19:38:21.000000000 +0200
+++ skia/ext/SkMemory_new_handler.cpp	2015-04-20 19:38:39.000000000 +0200
@@ -53,7 +53,7 @@
 static void* sk_malloc_nothrow(size_t size) {
     // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
     // doesn't work as intended everywhere.
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_FREEBSD)
     return malloc(size);
 #else
     void* result;
@@ -77,7 +77,7 @@
 void* sk_calloc(size_t size) {
     // TODO(b.kelemen): we should always use UncheckedCalloc but currently it
     // doesn't work as intended everywhere.
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_FREEBSD)
     return calloc(1, size);
 #else
     void* result;
