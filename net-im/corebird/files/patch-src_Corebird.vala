--- src/Corebird.vala.orig	2017-05-03 23:08:40 UTC
+++ src/Corebird.vala
@@ -194,7 +194,8 @@ public class Corebird : Gtk.Application 
     base.startup ();
     this.set_resource_base_path ("/org/baedert/corebird");
 
-    typeof (LazyMenuButton).ensure ();
+    new ComposeImageManager ();
+    new LazyMenuButton ();
 
 #if DEBUG
     GLib.Environment.set_variable ("G_MESSAGES_DEBUG", "corebird", true);
