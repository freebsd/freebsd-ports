--- src/file-manager/fm-directory-view.c.orig	Tue Feb 24 08:17:24 2004
+++ src/file-manager/fm-directory-view.c	Wed Feb 25 02:43:55 2004
@@ -4476,19 +4476,25 @@
 
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_MENU_PATH_SCRIPTS, 
-				    !any_scripts);
+				    FALSE);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_SCRIPTS, 
+				    FALSE);
+	nautilus_bonobo_set_hidden (view->details->ui,
+				    FM_DIRECTORY_VIEW_MENU_PATH_SCRIPTS_PLACEHOLDER,
+				    !any_scripts);
+	nautilus_bonobo_set_hidden (view->details->ui,
+				    FM_DIRECTORY_VIEW_POPUP_PATH_BACKGROUND_SCRIPTS_PLACEHOLDER,
 				    !any_scripts);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_BACKGROUND_SCRIPTS, 
-				    !any_scripts);
+				    FALSE);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_MENU_PATH_SCRIPTS_SEPARATOR, 
 				    !any_scripts);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_SCRIPTS_SEPARATOR, 
-				    !any_scripts);
+				    FALSE);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_BACKGROUND_SCRIPTS_SEPARATOR, 
 				    !any_scripts);
