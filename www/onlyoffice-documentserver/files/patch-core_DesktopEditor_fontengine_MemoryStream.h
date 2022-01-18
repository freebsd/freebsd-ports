--- core/DesktopEditor/fontengine/MemoryStream.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/fontengine/MemoryStream.h
@@ -41,7 +41,7 @@
 //#define _LOGGING_NATIVE_
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <stdlib.h>
 #endif
 
