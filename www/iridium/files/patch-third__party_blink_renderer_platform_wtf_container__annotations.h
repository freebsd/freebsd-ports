--- third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2019-03-11 22:01:04 UTC
+++ third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -10,7 +10,7 @@
 
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
-#if defined(ADDRESS_SANITIZER) && defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if defined(ADDRESS_SANITIZER) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
