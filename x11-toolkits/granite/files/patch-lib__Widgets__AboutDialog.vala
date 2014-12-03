--- ./lib/Widgets/AboutDialog.vala.orig	2014-05-25 19:42:24.000000000 +0000
+++ ./lib/Widgets/AboutDialog.vala	2014-07-27 13:06:32.000000000 +0000
@@ -65,7 +65,7 @@
 
         private Button help_button;
         private Button translate_button;
-        private Button bug_button;
+        private LinkButton bug_button;
 
         private Granite.Drawing.BufferSurface buffer;
 
@@ -128,15 +128,8 @@
             action_area.pack_start (translate_button, false, false, 0);
 
             /* bug button */
-            bug_button = new Button.with_label (_("Report a Problem"));
-            bug_button.clicked.connect (() => {
-                try {
-                    GLib.Process.spawn_command_line_async ("apport-bug %i".printf (Posix.getpid ()));
-                } catch (Error e) {
-                    warning ("Could Not Launch 'apport-bug'.");
-                    activate_link (bug);
-                }
-            });
+            string _uri = "https://bugs.freebsd.org/bugzilla/enter_bug.cgi";
+            bug_button = new LinkButton.with_label (_uri, _("Report a Problem"));
             action_area.pack_start (bug_button, false, false, 0);
 
             action_area.reorder_child (bug_button, 0);
