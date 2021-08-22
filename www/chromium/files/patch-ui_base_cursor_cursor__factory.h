--- ui/base/cursor/cursor_factory.h.orig	2021-07-19 18:45:43 UTC
+++ ui/base/cursor/cursor_factory.h
@@ -81,7 +81,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR_BASE) CursorFact
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR_BASE)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
