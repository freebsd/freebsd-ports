--- src/3rdparty/chromium/ui/base/cursor/cursor_factory.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/cursor/cursor_factory.h
@@ -93,7 +93,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) CursorFactory {
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
