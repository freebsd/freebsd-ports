--- ./midori/midori-view.c.orig	2013-03-07 17:44:14.000000000 +0000
+++ ./midori/midori-view.c	2013-03-07 23:30:37.000000000 +0000
@@ -3789,8 +3789,10 @@
     midori_view_add_version (markup, html, g_strdup_printf ("cairo %s (%s)\tlibnotify %s",
         CAIRO_VERSION_STRING, cairo_version_string (),
         LIBNOTIFY_VERSION));
+#if defined HAVE_GCR && defined HAVE_GRANITE
     midori_view_add_version (markup, html, g_strdup_printf ("gcr %s\tgranite %s",
         GCR_VERSION, GRANITE_VERSION));
+#endif
     midori_view_add_version (markup, html, g_strdup_printf ("single instance %s",
         #if HAVE_UNIQUE
         "libunique " UNIQUE_VERSION
