--- ./Source/WebCore/platform/graphics/surfaces/GraphicsSurfaceToken.h.orig	2012-12-18 20:04:31.000000000 +0100
+++ ./Source/WebCore/platform/graphics/surfaces/GraphicsSurfaceToken.h	2012-12-28 13:02:03.566975217 +0100
@@ -35,7 +35,7 @@
 
 #if OS(DARWIN)
     typedef mach_port_t BufferHandle;
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(FREEBSD)
     typedef uint32_t BufferHandle;
 #elif OS(WINDOWS)
     typedef HANDLE BufferHandle;
