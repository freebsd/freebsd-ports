--- core/DesktopEditor/fontengine/fontconverter/MemoryUtils.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/fontengine/fontconverter/MemoryUtils.h
@@ -37,7 +37,7 @@
 #include <string>
 #include <stdlib.h>
 
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
     #include <string.h>
 #endif
 
