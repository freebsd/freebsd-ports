--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2022-03-25 21:59:56 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -12,7 +12,7 @@
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
 #if defined(ADDRESS_SANITIZER) &&                      \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     defined(ARCH_CPU_X86_64)
 
 // Annotations require buffers to begin on an 8-byte boundary. See
