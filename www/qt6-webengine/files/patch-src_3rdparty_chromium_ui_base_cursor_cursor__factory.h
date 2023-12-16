--- src/3rdparty/chromium/ui/base/cursor/cursor_factory.h.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/ui/base/cursor/cursor_factory.h
@@ -88,7 +88,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) CursorFactory {
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
