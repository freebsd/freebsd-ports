
$FreeBSD$

--- addressbook/backend/pas/pas-backend-file.c	2001/12/06 10:25:50	1.1
+++ addressbook/backend/pas/pas-backend-file.c	2001/12/06 10:27:02
@@ -1238,10 +1238,13 @@
 	gboolean        writable = FALSE;
 	int             db_error;
 	DB *db;
+#if 0
 	int major, minor, patch;
+#endif
 
 	g_assert (bf->priv->loaded == FALSE);
 
+#if 0
 	db_version (&major, &minor, &patch);
 
 	if (major != 3 ||
@@ -1250,6 +1253,7 @@
 		g_warning ("Wrong version of libdb.");
 		return FALSE;
 	}
+#endif
 
 	filename = pas_backend_file_extract_path_from_uri (uri);
 
