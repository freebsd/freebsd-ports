--- hald/freebsd/hf-drm.c.orig	2008-08-10 15:50:10.000000000 +0200
+++ hald/freebsd/hf-drm.c	2012-09-27 12:04:28.000000000 +0200
@@ -234,6 +234,12 @@
   {
     HalDevice *parent = HAL_DEVICE(l->data);
 
+    if (hf_device_store_match(hald_get_gdl(),
+			      "info.parent", HAL_PROPERTY_TYPE_STRING, hal_device_get_udi(parent),
+			      "info.subsystem", HAL_PROPERTY_TYPE_STRING, "drm",
+			      NULL))
+      continue;
+
     if (! hal_device_property_get_bool(parent, "info.ignore"))
       {
         Card *card;
