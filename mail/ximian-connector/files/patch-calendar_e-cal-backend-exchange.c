--- calendar/e-cal-backend-exchange.c.orig	Sat Mar 19 14:24:33 2005
+++ calendar/e-cal-backend-exchange.c	Sat Mar 19 14:25:06 2005
@@ -1432,6 +1432,7 @@
 	e_cal_component_get_uid (comp, &uid);
 	e_cal_component_get_attachment_list (comp, &attach_list);
 	for (l = attach_list; l ; l = l->next){
+		char *mime_type;
 		if (!strncmp ((char *)l->data, "file://", 7)) {
 			fname = (char *)(l->data) + strlen ("file://");
 			filename = g_strrstr (fname, "/") + 1;
@@ -1461,7 +1462,7 @@
 		camel_data_wrapper_construct_from_stream (wrapper, stream);
 		camel_object_unref (stream);
 
-		char *mime_type = gnome_vfs_get_mime_type (dest_url + strlen ("file://"));
+		mime_type = gnome_vfs_get_mime_type (dest_url + strlen ("file://"));
 		type = camel_content_type_decode (mime_type);
 		camel_data_wrapper_set_mime_type_field (wrapper, type);
 		camel_content_type_unref (type);
