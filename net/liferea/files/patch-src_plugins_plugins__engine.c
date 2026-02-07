commit f07f07bcd1a0b996657bcae067d5fae5a5b03686
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    use gi_repository_new() on old glib
    
    According to the documentation[1], the gi_repository_dup_default()
    method was introduced in GLib 2.86 - and gi_repository_new() looks
    like the closest replacement.
    Use a compile time check to catch this in for old GLib versions
    only.
    
    [1]: https://docs.gtk.org/girepository/type_func.Repository.dup_default.html

diff --git src/plugins/plugins_engine.c src/plugins/plugins_engine.c
index 9a5a1358..e39665be 100644
--- src/plugins/plugins_engine.c
+++ src/plugins/plugins_engine.c
@@ -111,13 +111,20 @@ liferea_plugins_engine_init (LifereaPluginsEngine *plugins)
 		g_error_free (error);
 		error = NULL;
 	}
-#else
+#elif GLIB_CHECK_VERSION(2, 86, 0)
 	if (!gi_repository_require_private (gi_repository_dup_default (),
 		typelib_dir, "Liferea", "3.0", 0, &error)) {
 		g_warning ("Could not load Liferea repository: %s", error->message);
 		g_error_free (error);
 		error = NULL;
 	}
+#else
+	if (!gi_repository_require_private (gi_repository_new (),
+		typelib_dir, "Liferea", "3.0", 0, &error)) {
+		g_warning ("Could not load Liferea repository: %s", error->message);
+		g_error_free (error);
+		error = NULL;
+	}
 #endif
 
 	g_autofree gchar *userdata = g_build_filename (g_get_user_data_dir (), "liferea", "plugins", NULL);
