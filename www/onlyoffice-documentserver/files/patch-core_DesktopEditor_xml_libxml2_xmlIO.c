--- core/DesktopEditor/xml/libxml2/xmlIO.c.orig	2021-12-24 14:29:10 UTC
+++ core/DesktopEditor/xml/libxml2/xmlIO.c
@@ -43,7 +43,7 @@
 #include <windows.h>
 #include "io.h"
 #endif
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "unistd.h"
 #endif
 
