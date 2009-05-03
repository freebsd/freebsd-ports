--- programs/spectra/gspectrum.cc.orig	2009-05-03 13:58:03.000000000 -0400
+++ programs/spectra/gspectrum.cc	2009-05-03 13:58:10.000000000 -0400
@@ -65,7 +65,7 @@ int main (int argc, char *argv[])
 	// create a new Application. This initialize Goffice
 	gsvApplication *App = new gsvApplication ();
 	// Initialize plugins manager
-	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
+	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_TYPE_PLUGIN_LOADER_MODULE);
 	gsvDocument *pDoc = App->OnFileNew();
 	char *path, *uri;
 	bool bres = false;
