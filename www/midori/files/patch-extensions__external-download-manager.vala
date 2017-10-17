--- extensions/external-download-manager.vala.orig	2015-08-30 11:56:26 UTC
+++ extensions/external-download-manager.vala
@@ -10,7 +10,7 @@
 */
 
 namespace EDM {
-#if !HAVE_WIN32
+#if !HAVE_WIN32 || HAVE_GTK3
     [DBus (name = "net.launchpad.steadyflow.App")]
     interface SteadyflowInterface : GLib.Object {
         public abstract void AddFile (string url) throws IOError;
@@ -203,6 +203,7 @@ namespace EDM {
         }
     }
 
+#if HAVE_GTK3
     private class SteadyFlow : ExternalDownloadManager {
         public override bool download (DownloadRequest dlReq) {
             try {
@@ -230,6 +231,7 @@ namespace EDM {
         }
     }
 #endif
+#endif
 
     private class CommandLinePreferences : Gtk.Dialog {
         protected Gtk.Entry input;
@@ -359,7 +361,9 @@ public Katze.Array extension_init () {
     var extensions = new Katze.Array( typeof (Midori.Extension));
     #if !HAVE_WIN32
     extensions.add_item (new EDM.Aria2 ());
+    #if HAVE_GTK3
     extensions.add_item (new EDM.SteadyFlow ());
+    #endif
     #endif
     extensions.add_item (new EDM.CommandLine ());
     return extensions;
