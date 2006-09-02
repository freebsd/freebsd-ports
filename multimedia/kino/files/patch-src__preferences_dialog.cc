--- src/preferences_dialog.cc.orig	Fri Jul 14 08:11:36 2006
+++ src/preferences_dialog.cc	Sat Sep  2 19:34:27 2006
@@ -34,8 +34,10 @@
 #include "support.h"
 #include "commands.h"
 #include "message.h"
+#if 0
 #include <libavc1394/avc1394.h>
 #include <libavc1394/rom1394.h>
+#endif
 
 	/* Declare callbacks for the jogshuttle handling */
 	static void
@@ -67,9 +69,13 @@
 		GtkWidget* glade_menuitem;
 		GtkWidget* widget;
 		int currentNode, itemCount = 0, currentItem = 0;
+#if 0
 		rom1394_directory rom1394_dir;
+#endif
 		glade_menu = gtk_menu_new ();
+#if 0
 		static raw1394handle_t handle;
+#endif
 
 		media_ctrl_key *mkeys;
 		
@@ -312,6 +318,7 @@
 #ifdef HAVE_DV1394
 		gtk_widget_hide_all( lookup_widget( dialog, "hbox_ieee1394_warning" ) );
 #endif
+#if 0
 		if ( ( handle = raw1394_new_handle() ) )
 		{
 			raw1394_portinfo ports[MAX_1394_PORTS];
@@ -373,6 +380,7 @@
 				}
 			}
 		}
+#endif
 
 		gtk_option_menu_set_menu ( GTK_OPTION_MENU ( widget ), glade_menu );
 		gtk_option_menu_set_history( GTK_OPTION_MENU( widget ), currentItem );
@@ -409,7 +417,9 @@
 	void
 	on_avc_phyid_activate( GtkMenuItem * menu_item, gpointer user_data )
 	{
+#if 0
 		strncpy( Preferences::getInstance().avcGUID, (char *) user_data, 64 );
+#endif
 	}
 
 	void
