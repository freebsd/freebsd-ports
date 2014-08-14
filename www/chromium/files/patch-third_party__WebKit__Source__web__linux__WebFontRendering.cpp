--- ./third_party/WebKit/Source/web/linux/WebFontRendering.cpp.orig	2014-08-12 21:07:15.000000000 +0200
+++ ./third_party/WebKit/Source/web/linux/WebFontRendering.cpp	2014-08-13 09:56:58.000000000 +0200
@@ -34,7 +34,7 @@
 #include "platform/fonts/FontDescription.h"
 #include "platform/fonts/FontPlatformData.h"
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
 #include "public/platform/linux/WebFontInfo.h"
 #endif
 
@@ -77,7 +77,7 @@
 void WebFontRendering::setSubpixelPositioning(bool useSubpixelPositioning)
 {
     FontDescription::setSubpixelPositioning(useSubpixelPositioning);
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
     WebFontInfo::setSubpixelPositioning(useSubpixelPositioning);
 #endif
 }
