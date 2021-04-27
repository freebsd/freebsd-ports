--- ui/base/cursor/cursor_factory.h.orig	2021-04-22 08:30:28 UTC
+++ ui/base/cursor/cursor_factory.h
@@ -67,7 +67,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR_BASE) CursorFact
   virtual void ObserveThemeChanges();
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR_BASE)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
