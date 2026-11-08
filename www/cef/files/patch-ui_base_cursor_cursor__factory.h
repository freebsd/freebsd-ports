--- ui/base/cursor/cursor_factory.h.orig	2026-08-12 09:02:10 UTC
+++ ui/base/cursor/cursor_factory.h
@@ -94,7 +94,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) CursorFactory {
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 
