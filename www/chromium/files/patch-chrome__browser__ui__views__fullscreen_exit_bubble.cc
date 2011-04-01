--- ./chrome/browser/ui/views/fullscreen_exit_bubble.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/fullscreen_exit_bubble.cc	2010-12-20 20:15:08.000000000 +0100
@@ -18,7 +18,7 @@
 #if defined(OS_WIN)
 #include "app/l10n_util_win.h"
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -119,7 +119,7 @@
     return MA_NOACTIVATE;
   }
 };
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 // TODO: figure out the equivalent of MA_NOACTIVATE for gtk.
 #endif
 
@@ -154,7 +154,7 @@
   popup_->set_window_style(WS_POPUP);
   popup_->set_window_ex_style(WS_EX_LAYERED | WS_EX_TOOLWINDOW |
                               l10n_util::GetExtendedTooltipStyles());
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   popup_ = new views::WidgetGtk(views::WidgetGtk::TYPE_POPUP);
   popup_->MakeTransparent();
 #endif
@@ -202,7 +202,7 @@
 #if defined(OS_WIN)
     popup_->MoveWindow(popup_rect.x(), popup_rect.y(), popup_rect.width(),
                        popup_rect.height());
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
     popup_->SetBounds(popup_rect);
 #endif
     popup_->Show();
