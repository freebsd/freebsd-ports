--- src/3rdparty/chromium/content/public/common/content_switches.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/content/public/common/content_switches.h
@@ -108,6 +108,7 @@ CONTENT_EXPORT extern const char kEnableLogging[];
 CONTENT_EXPORT extern const char kEnableIsolatedWebAppsInRenderer[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnablePluginPlaceholderTesting[];
@@ -264,7 +265,7 @@ CONTENT_EXPORT extern const char kPreventResizingConte
 CONTENT_EXPORT extern const char kPreventResizingContentsForTesting[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
