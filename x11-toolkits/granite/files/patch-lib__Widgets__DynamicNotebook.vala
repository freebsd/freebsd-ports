--- lib/Widgets/DynamicNotebook.vala.orig	2014-11-07 00:23:26.781146868 +0100
+++ lib/Widgets/DynamicNotebook.vala	2014-11-07 00:24:59.547141822 +0100
@@ -505,10 +505,19 @@
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
