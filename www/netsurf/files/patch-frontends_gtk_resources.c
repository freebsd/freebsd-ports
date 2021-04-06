--- frontends/gtk/resources.c.orig	2021-04-01 19:00:43 UTC
+++ frontends/gtk/resources.c
@@ -82,6 +82,11 @@ static struct nsgtk_resource_s ui_resource[] = {
 	RES_ENTRY("globalhistory"),
 	RES_ENTRY("localhistory"),
 	RES_ENTRY("options"),
+	RES_ENTRY("deoptions"),
+	RES_ENTRY("enoptions"),
+	RES_ENTRY("froptions"),
+	RES_ENTRY("itoptions"),
+	RES_ENTRY("nloptions"),
 	RES_ENTRY("hotlist"),
 	RES_ENTRY("cookies"),
 	RES_ENTRY("viewdata"),
@@ -552,6 +557,7 @@ nsgtk_builder_new_from_resname(const char *resname, Gt
 			      error->message);
 			g_error_free(error);
 			g_object_unref(G_OBJECT(new_builder));
+			
 			return NSERROR_INIT_FAILED;
 		}
 	} else {
