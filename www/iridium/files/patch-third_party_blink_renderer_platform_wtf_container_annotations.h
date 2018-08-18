--- third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2018-07-19 20:16:53.004477000 +0200
+++ third_party/blink/renderer/platform/wtf/container_annotations.h	2018-07-19 20:17:16.730907000 +0200
@@ -10,7 +10,7 @@
 
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
-#if defined(ADDRESS_SANITIZER) && defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if defined(ADDRESS_SANITIZER) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
