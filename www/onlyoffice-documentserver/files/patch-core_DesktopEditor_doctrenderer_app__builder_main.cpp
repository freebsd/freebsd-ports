--- core/DesktopEditor/doctrenderer/app_builder/main.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/app_builder/main.cpp
@@ -34,7 +34,7 @@
 #include "../docbuilder.h"
 #include "../../common/File.h"
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include "../../../DesktopEditor/common/File.h"
 #endif
 
