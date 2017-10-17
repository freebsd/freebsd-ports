--- extensions/history-list.vala.orig	2015-08-30 11:56:26 UTC
+++ extensions/history-list.vala
@@ -223,7 +223,11 @@ namespace HistoryList {
                     FixMe: the retrun value of `Gtk.ListStore.remove` should be checked
                     Note:  in some cases the return value of `Gtk.ListStore.remove` is wrong
                 */
+#if VALA_0_36
+                model.remove (ref iter);
+#else
                 model.remove (iter);
+#endif
                 this.browser.close_tab (view);
                 if (length > 2)
                     this.resize_treeview ();
