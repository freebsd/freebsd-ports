--- third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2021-04-14 18:41:11 UTC
+++ third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -12,7 +12,7 @@
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
 #if defined(ADDRESS_SANITIZER) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
@@ -37,7 +37,7 @@
   ANNOTATE_NEW_BUFFER(buffer, newCapacity, bufferSize);
 // Annotations require buffers to begin on an 8-byte boundary.
 
-#else  // ADDRESS_SANITIZER && (OS_LINUX || IS_CHROMEOS_ASH) &&
+#else  // ADDRESS_SANITIZER && (OS_LINUX || IS_CHROMEOS_ASH || OS_BSD) &&
        // ARCH_CPU_X86_64
 
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)
@@ -45,7 +45,7 @@
 #define ANNOTATE_CHANGE_SIZE(buffer, capacity, oldSize, newSize)
 #define ANNOTATE_CHANGE_CAPACITY(buffer, oldCapacity, bufferSize, newCapacity)
 
-#endif  // ADDRESS_SANITIZER && (OS_LINUX || IS_CHROMEOS_ASH) &&
+#endif  // ADDRESS_SANITIZER && (OS_LINUX || IS_CHROMEOS_ASH || OS_BSD) &&
         // ARCH_CPU_X86_64
 
 #endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_WTF_CONTAINER_ANNOTATIONS_H_
