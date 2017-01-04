--- src/gtk/application.vala.orig	2016-10-30 08:24:08 UTC
+++ src/gtk/application.vala
@@ -26,7 +26,7 @@ private const string G_LOG_DOMAIN="Diori
 namespace Diorite
 {
 	
-#if LINUX
+#if __FALSE__
 [CCode (cheader_filename = "sys/prctl.h", cname = "prctl")]
 extern int prctl (int option, string arg2, ulong arg3, ulong arg4, ulong arg5);
 #endif
@@ -67,7 +67,7 @@ public abstract class Application : Gtk.
 		this.desktop_name = desktop_name;
 		this.app_id = app_id;
 		actions = new ActionsRegistry(this);
-		#if LINUX
+		#if __FALSE__
 		prctl(15, app_id, 0, 0, 0);
 		#endif
 		GLib.Environment.set_prgname(app_id);
