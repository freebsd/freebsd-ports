--- mozilla-plugin/chem-viewer.cc.orig	2009-05-03 13:53:24.000000000 -0400
+++ mozilla-plugin/chem-viewer.cc	2009-05-03 13:53:34.000000000 -0400
@@ -299,7 +299,7 @@ int main (int argc, char *argv[])
 	}
 #endif
 	libgoffice_init ();
-	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
+	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_TYPE_PLUGIN_LOADER_MODULE);
 	in_channel = g_io_channel_unix_new (fileno (stdin));
 	g_io_add_watch (in_channel, G_IO_IN, io_func, &error);
 	gtk_main ();
