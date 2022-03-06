--- Source/WebCore/platform/PlatformScreen.h.orig	2021-10-21 08:52:09 UTC
+++ Source/WebCore/platform/PlatformScreen.h
@@ -48,6 +48,12 @@ OBJC_CLASS UIScreen;
 typedef struct CGColorSpace *CGColorSpaceRef;
 #endif
 
+// X11 headers define a bunch of macros with common terms, interfering with WebCore and WTF enum values.
+// As a workaround, we explicitly undef them here.
+#if defined(None)
+#undef None
+#endif
+
 namespace WebCore {
 
 class DestinationColorSpace;
