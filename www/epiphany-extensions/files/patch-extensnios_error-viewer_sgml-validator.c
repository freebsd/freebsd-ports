--- extensions/error-viewer/sgml-validator.c.orig	Wed Jun  9 15:37:19 2004
+++ extensions/error-viewer/sgml-validator.c	Wed Jun  9 15:37:41 2004
@@ -436,9 +436,10 @@
 static gboolean
 sgml_validator_append_internal (gpointer data)
 {
+	SgmlValidatorAppendCBData *append_data;
 	g_return_if_fail (data != NULL);
 
-	SgmlValidatorAppendCBData *append_data =
+	append_data =
 		(SgmlValidatorAppendCBData *) data;
 
 	error_viewer_append (append_data->validator->priv->error_viewer,
