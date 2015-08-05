--- lib/Widgets/ContractorView.vala.orig	2015-08-02 23:43:12.064726000 +0200
+++ lib/Widgets/ContractorView.vala	2015-08-02 23:43:58.610804000 +0200
@@ -35,7 +35,7 @@
     public delegate void ContractCallback ();
     private Gee.HashMap<int, DelegateWrapper?> outsiders;
     private int[] blacklisted_pos;
-    private ListStore list;
+    private Gtk.ListStore list;
 
     private struct DelegateWrapper { unowned ContractCallback method; }
     
@@ -73,7 +73,7 @@
      */
     public ContractorView (string filename, string mime, int icon_size = 32, bool show_contract_name = true) {
         /* Setup the ListStore */
-        list = new ListStore (2, typeof (Gdk.Pixbuf), typeof (string));
+        list = new Gtk.ListStore (2, typeof (Gdk.Pixbuf), typeof (string));
         outsiders = new Gee.HashMap<int, DelegateWrapper?> ();
         this.model = list;
         
