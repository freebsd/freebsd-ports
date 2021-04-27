--- ui/base/cursor/cursor_factory.cc.orig	2021-04-22 08:30:09 UTC
+++ ui/base/cursor/cursor_factory.cc
@@ -68,7 +68,7 @@ void CursorFactory::ObserveThemeChanges() {
   NOTIMPLEMENTED();
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
@@ -185,6 +185,6 @@ std::vector<std::string> CursorNamesFromType(mojom::Cu
   return {"left_ptr"};
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace ui
