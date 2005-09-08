--- src/eiciel_nautilus_page.cpp.orig	Thu Sep  8 23:32:08 2005
+++ src/eiciel_nautilus_page.cpp	Thu Sep  8 23:21:13 2005
@@ -97,6 +97,10 @@
 	// Si és local obtenim el path del fitxer
 	local_file = gnome_vfs_get_local_path_from_uri(uri);
 	g_free(guri);
+	if (!local_file)
+	{
+		return NULL;
+	}
 
 	// Inicialitzem gtkmm
 	// TODO - ¿?¿? Preguntar a la gent de gtkmm
