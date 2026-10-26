--- panels/info-overview/cc-info-overview-panel.c.orig	2023-08-01 19:09:00 UTC
+++ panels/info-overview/cc-info-overview-panel.c
@@ -40,6 +40,9 @@
 #include <udisks/udisks.h>
 #include <gudev/gudev.h>
 
+#include <limits.h>
+#include <unistd.h>
+
 #include <gdk/gdk.h>
 
 #ifdef GDK_WINDOWING_WAYLAND
@@ -64,6 +67,7 @@ struct _CcInfoOverviewPanel
   CcListRow       *graphics_row;
   GtkListBox      *hardware_box;
   CcListRow       *hardware_model_row;
+  GtkListBox      *hostname_box;
   GtkDialog       *hostname_editor;
   CcHostnameEntry *hostname_entry;
   CcListRow       *hostname_row;
@@ -701,6 +705,21 @@ info_overview_panel_setup_virt (CcInfoOverviewPanel *s
   set_virtualization_label (self, g_variant_get_string (inner, NULL));
 }
 
+static char *
+get_hostname_fallback (void)
+{
+  char localhost[_POSIX_HOST_NAME_MAX + 1] = "";
+  if (gethostname (localhost, _POSIX_HOST_NAME_MAX) == 0)
+    {
+      if (g_strcmp0 ((char *)localhost, "") > 0)
+        return (char *)localhost;
+      else
+        return "localhost";
+    }
+  else
+    return "localhost";
+}
+
 static const char *
 get_windowing_system (void)
 {
@@ -771,6 +790,8 @@ info_overview_panel_setup_overview (CcInfoOverviewPane
   if (load_budgie_version (&budgie_version))
     cc_list_row_set_secondary_label (self->budgie_version_row, budgie_version);
 
+  cc_list_row_set_secondary_label (self->hostname_row, get_hostname_fallback ());
+
   cc_list_row_set_secondary_label (self->windowing_system_row, get_windowing_system ());
 
   hardware_model_text = get_hardware_model_string ();
@@ -948,9 +969,7 @@ cc_info_panel_row_activated_cb (CcInfoOverviewPanel *s
   g_assert (CC_IS_INFO_OVERVIEW_PANEL (self));
   g_assert (CC_IS_LIST_ROW (row));
 
-  if (row == self->hostname_row)
-    open_hostname_edit_dialog (self);
-  else if (row == self->software_updates_row)
+  if (row == self->software_updates_row)
     open_software_update (self);
 }
 
@@ -1018,6 +1037,7 @@ cc_info_overview_panel_class_init (CcInfoOverviewPanel
   gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, graphics_row);
   gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, hardware_box);
   gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, hardware_model_row);
+  gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, hostname_box);
   gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, hostname_editor);
   gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, hostname_entry);
   gtk_widget_class_bind_template_child (widget_class, CcInfoOverviewPanel, hostname_row);
