--- src/3rdparty/chromium/third_party/WebKit/Source/wtf/ContainerAnnotations.h.orig	2017-01-26 00:49:28 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/wtf/ContainerAnnotations.h
@@ -10,7 +10,7 @@
 
 // TODO(ochang): Remove the CPU(X86_64) condition to enable this for X86 once
 // the crashes there have been fixed: http://crbug.com/461406
-#if defined(ADDRESS_SANITIZER) && OS(LINUX) && CPU(X86_64)
+#if defined(ADDRESS_SANITIZER) && (OS(LINUX) || OS(BSD)) && CPU(X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
