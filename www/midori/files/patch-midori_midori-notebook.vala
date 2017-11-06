--- midori/midori-notebook.vala.orig	2015-08-30 11:56:26 UTC
+++ midori/midori-notebook.vala
@@ -10,7 +10,7 @@
 */
 
 namespace Midori {
-    protected class Tally : Gtk.EventBox {
+    internal class Tally : Gtk.EventBox {
         public Midori.Tab tab { get; set; }
         Gtk.Spinner spinner;
         public Gtk.Label label;
@@ -22,7 +22,7 @@ namespace Midori {
         public bool close_button_left { get; set; default = false; }
         public bool close_button_visible { get; set; default = false; }
 
-        protected Tally (Midori.Tab tab) {
+        internal Tally (Midori.Tab tab) {
             this.tab = tab;
             box = new Gtk.HBox (false, 1);
             add (box);
@@ -155,7 +155,7 @@ namespace Midori {
         int last_tab_size = 0;
 
 #if !HAVE_GTK3
-        static const string style_fixup = """
+        const string style_fixup = """
             style "midori-close-button-style"
             {
             GtkWidget::focus-padding = 0
