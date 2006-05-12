--- gtk/gtkmm/uimanager.cc.orig	Fri May 12 16:35:32 2006
+++ gtk/gtkmm/uimanager.cc	Fri May 12 16:36:27 2006
@@ -42,7 +42,7 @@ UIManager::ui_merge_id UIManager::add_ui
   guint retvalue = gtk_ui_manager_add_ui_from_string(gobj(), buffer.c_str(), buffer.size(), &(gerror));
 
 #ifdef GLIBMM_EXCEPTIONS_ENABLED
-  if(error) ::Glib::Error::throw_exception(gerror);
+  if(gerror) ::Glib::Error::throw_exception(gerror);
 #else
   error = ::Glib::Error::throw_exception(gerror);
 #endif //GLIBMM_EXCEPTIONS_ENABLED
