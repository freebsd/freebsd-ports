--- components/image_properties/nautilus-image-properties-view.c.orig	Thu Sep 30 15:41:33 2004
+++ components/image_properties/nautilus-image-properties-view.c	Thu Sep 30 15:43:11 2004
@@ -130,7 +130,8 @@
 		return;
 	}
 
-        attribute->value = g_strdup (exif_content_get_value (content, attribute->tag));
+        char value[1024];
+        attribute->value = g_strdup (exif_content_get_value (content, attribute->tag, value, sizeof(value)));
 	if (attribute->value != NULL) {
 		attribute->found = TRUE;
 	}
