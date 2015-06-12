--- gtk/status_icon.c.orig	2015-05-13 14:47:31 UTC
+++ gtk/status_icon.c
@@ -195,7 +194,7 @@ static LinphoneStatusIcon *_linphone_sta
 }
 
 static void _linphone_status_icon_free(LinphoneStatusIcon *obj) {
-	if(obj->desc->uninit) obj->desc->uninit(obj->data);
+	if(obj->desc->uninit) obj->desc->uninit(obj);
 	if(obj->params) linphone_status_icon_params_unref(obj->params);
 	g_free(obj);
 }
