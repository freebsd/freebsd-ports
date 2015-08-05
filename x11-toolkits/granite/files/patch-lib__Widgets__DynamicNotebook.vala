--- lib/Widgets/DynamicNotebook.vala.orig	2014-05-25 21:42:24.000000000 +0200
+++ lib/Widgets/DynamicNotebook.vala	2015-08-02 23:42:37.151406000 +0200
@@ -658,10 +658,19 @@
        /**
         * The text shown in the add button tooltip
         */
+#if VALA_0_26
+        public string add_button_tooltip {
+            get { _add_button_tooltip = add_button.tooltip_text; return _add_button_tooltip; }
+            set { add_button.tooltip_text = value; }
+        }
+        // Use temporary field to avoid breaking API this can be dropped while preparing for 0.4
+        string _add_button_tooltip;
+#else
         public string add_button_tooltip {
             get { return add_button.tooltip_text; }
             set { add_button.tooltip_text = value; }
         }
+#endif
 
         public Tab current {
             get { return tabs.nth_data (notebook.get_current_page ()); }
@@ -918,7 +927,7 @@
             notebook.create_window.connect (on_create_window);
         }
 
-        ~Notebook () {
+        ~DynamicNotebook () {
             notebook.switch_page.disconnect (on_switch_page);
             notebook.page_added.disconnect (on_page_added);
             notebook.page_removed.disconnect (on_page_removed);
