--- third_party/WebKit/Source/platform/wtf/ContainerAnnotations.h.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/wtf/ContainerAnnotations.h	2017-09-06 22:18:52.135596000 +0200
@@ -10,7 +10,7 @@
 
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
-#if defined(ADDRESS_SANITIZER) && defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if defined(ADDRESS_SANITIZER) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
