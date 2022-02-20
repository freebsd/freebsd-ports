--- ui/base/clipboard/clipboard_constants.h.orig	2022-02-07 13:39:41 UTC
+++ ui/base/clipboard/clipboard_constants.h
@@ -38,7 +38,7 @@ COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeOctetStream[];
 
 // Linux-specific MIME type constants (also used in Fuchsia).
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
