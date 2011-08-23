--- src/fx_main.c.orig	2011-08-12 14:28:22.000000000 +0200
+++ src/fx_main.c	2011-08-12 14:28:39.000000000 +0200
@@ -124,8 +124,8 @@ void fx_main_initialize(FxMain* fxmain)
 			SKIN_DIR"offline.svg");
 	gtk_status_icon_set_tooltip(fxmain->trayIcon, "OpenFetion");
 #ifdef USE_LIBNOTIFY
-	fxmain->notify = notify_notification_new_with_status_icon("welcome"
-			, "" , NULL , fxmain->trayIcon);
+	fxmain->notify = notify_notification_new("welcome"
+			, "" , NULL);
 	notify_notification_set_timeout(fxmain->notify , 2500);
 #endif
 
