--- third_party/WebKit/Source/WebKit/chromium/src/PlatformBridge.cpp.orig	2011-03-20 22:02:04.338736765 +0200
+++ third_party/WebKit/Source/WebKit/chromium/src/PlatformBridge.cpp	2011-03-20 22:02:04.469737772 +0200
@@ -778,7 +778,7 @@
         gc->platformContext()->canvas(), barRect, valueRect, determinate, animatedSeconds);
 }
 
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(FREEBSD)
 
 static WebThemeEngine::Part WebThemePart(PlatformBridge::ThemePart part)
 {
