--- ui/views/test/widget_test_aura.cc.orig	2021-09-24 18:58:31 UTC
+++ ui/views/test/widget_test_aura.cc
@@ -15,7 +15,7 @@
 #include "ui/views/widget/widget.h"
 #include "ui/wm/core/shadow_controller.h"
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
@@ -74,7 +74,7 @@ BOOL CALLBACK FindAllWindowsCallback(HWND hwnd, LPARAM
 
 std::vector<aura::Window*> GetAllTopLevelWindows() {
   std::vector<aura::Window*> roots;
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   roots = DesktopWindowTreeHostLinux::GetAllOpenWindows();
 #elif defined(OS_WIN)
@@ -130,7 +130,7 @@ gfx::Size WidgetTest::GetNativeWidgetMinimumContentSiz
   return widget->GetNativeWindow()->delegate()->GetMinimumSize();
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #if defined(USE_OZONE)
   if (features::IsUsingOzonePlatform())
     return widget->GetNativeWindow()->delegate()->GetMinimumSize();
@@ -144,7 +144,7 @@ gfx::Size WidgetTest::GetNativeWidgetMinimumContentSiz
       &hints);
   return gfx::Size(hints.min_width, hints.min_height);
 #endif  // USE_X11
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX || OS_BSD) && !OS_CHROMEOS
   NOTREACHED();
   return gfx::Size();
 }
