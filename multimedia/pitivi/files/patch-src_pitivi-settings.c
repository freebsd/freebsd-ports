--- src/pitivi-settings.c.orig	Mon Dec 20 13:52:35 2004
+++ src/pitivi-settings.c	Mon Dec 20 13:54:23 2004
@@ -385,6 +385,7 @@
   if (factory->numpadtemplates) {
     gint i;
     const GList *pads;
+    PitiviSettingsMimeType *tmp_mime;
     
     pads = factory->padtemplates;
     for (i = 0; pads; i++, pads = g_list_next (pads)) {
@@ -393,7 +394,6 @@
 	GstCaps *tmp_caps;
 
 	tmp_caps = (GstCaps *) padtemplate->caps;
-	PitiviSettingsMimeType *tmp_mime;
 	
 	if (!gst_caps_is_any (tmp_caps)) {
 	  if ((tmp_mime = pitivi_settings_search_flux (list, tmp_caps))) {
