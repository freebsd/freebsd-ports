--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h
@@ -37,14 +37,14 @@ COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES) extern const
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES) extern const char kMimeTypePNG[];
 
 // Linux-specific MIME type constants (also used in Fuchsia).
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxString[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxText[];
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 #if !defined(OS_APPLE) || defined(TOOLKIT_QT)
 // TODO(dcheng): This name is temporary. See crbug.com/106449.
