--- panels/system/about/cc-about-page.c.orig	2025-05-26 08:10:04 UTC
+++ panels/system/about/cc-about-page.c
@@ -159,7 +159,7 @@ cc_about_page_dispose (GObject *object)
   CcAboutPage *self = CC_ABOUT_PAGE (object);
 
   if (self->system_details_window)
-    adw_dialog_close (self->system_details_window);
+    adw_dialog_force_close (self->system_details_window);
   g_clear_object (&self->system_details_window);
 
   g_clear_handle_id (&self->create_system_details_id, g_source_remove);
