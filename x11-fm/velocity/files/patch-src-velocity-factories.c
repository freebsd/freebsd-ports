--- src/velocity-factories.c.orig	Thu Jul 24 16:44:17 2003
+++ src/velocity-factories.c	Wed Dec 10 20:22:05 2003
@@ -30,14 +30,14 @@
 		velocity_view*vview=(velocity_view*)g_object_get_data(G_OBJECT(mi),"velocity_view");   /*Always set by the factories for convenience*/
 		GtkWidget*sm=gtk_menu_item_get_submenu(mi);
 		gboolean empty;
-		if(!sm){
-			sm=gtk_menu_new();
-			gtk_menu_item_set_submenu(mi,sm);
-		}
 		void*fs[]={VELOCITY_MENU_FACTORY_DIRECTORY,(gpointer)uri,(gpointer)filter,
 				(gpointer)show_self,(gpointer)depth,NULL,(gpointer)enabled,
 				callback,callback_data,
 			NULL};
+		if(!sm){
+			sm=gtk_menu_new();
+			gtk_menu_item_set_submenu(mi,sm);
+		}
 		velocity_menu_factory_append(vview,sm,fs);
 		empty=(gboolean)g_object_get_data(G_OBJECT(sm),"velocity_menu_factory_dir_empty");
 		if(empty){
