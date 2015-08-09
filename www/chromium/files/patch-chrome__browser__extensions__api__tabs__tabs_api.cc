--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2015-08-02 00:29:44.653703000 -0400
+++ chrome/browser/extensions/api/tabs/tabs_api.cc	2015-08-02 00:32:45.945039000 -0400
@@ -659,7 +659,7 @@
 
   WindowController* controller = new_window->extension_window_controller();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On Desktop Linux, window managers may ignore hints until the X11 window is
   // mapped, which happens in the blocking call to Show() above.
   // DesktopWindowTreeHostX11 currently only checks for an attempt to maximize
@@ -669,7 +669,7 @@
   if (create_params.initial_show_state == ui::SHOW_STATE_MINIMIZED)
     new_window->window()->Minimize();
 #endif
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)) || defined(OS_WIN)
   // On Desktop Linux and Windows, managers don't handle fullscreen state to
   // create window for now.
   if (create_params.initial_show_state == ui::SHOW_STATE_FULLSCREEN)
