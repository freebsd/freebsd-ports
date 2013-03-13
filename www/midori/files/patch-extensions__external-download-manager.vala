--- ./extensions/external-download-manager.vala.orig	2013-03-07 17:44:14.000000000 +0000
+++ ./extensions/external-download-manager.vala	2013-03-11 06:50:27.000000000 +0000
@@ -16,7 +16,7 @@
 using WebKit;
 
 namespace EDM {
-#if !HAVE_WIN32
+#if !HAVE_WIN32 || HAVE_GTK3
     [DBus (name = "net.launchpad.steadyflow.App")]
     interface SteadyflowInterface : GLib.Object {
         public abstract void AddFile (string url) throws IOError;
@@ -183,6 +183,7 @@
         }
     }
 
+#if HAVE_GTK3
     private class SteadyFlow : ExternalDownloadManager {
         public override bool download (DownloadRequest dlReq) {
             try {
@@ -210,6 +211,7 @@
         }
     }
 #endif
+#endif
 
     private class CommandLinePreferences : Gtk.Dialog {
         protected Entry input;
@@ -339,8 +341,10 @@
     var extensions = new Katze.Array( typeof (Midori.Extension));
     #if !HAVE_WIN32
     extensions.add_item (new EDM.Aria2 ());
+    #if HAVE_GTK3
     extensions.add_item (new EDM.SteadyFlow ());
     #endif
+    #endif
     extensions.add_item (new EDM.CommandLine ());
     return extensions;
 }
