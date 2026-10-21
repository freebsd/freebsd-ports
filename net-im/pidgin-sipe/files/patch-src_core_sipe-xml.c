--- src/core/sipe-xml.c.orig
+++ src/core/sipe-xml.c
@@ -154,7 +154,7 @@
 	g_free(errmsg);
 }
 
-static void callback_serror(void *user_data, xmlErrorPtr error)
+static void callback_serror(void *user_data, const struct _xmlError *error)
 {
 	struct _parser_data *pd = user_data;
 
