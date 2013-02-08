--- ./midori/midori-view.c.orig	2013-02-05 23:28:05.000000000 +0000
+++ ./midori/midori-view.c	2013-02-06 22:29:13.000000000 +0000
@@ -3981,10 +3981,12 @@
                 gchar const* version_strings[] = {
                     LIBSOUP_VERSION,
                     CAIRO_VERSION_STRING, cairo_version_string (),
+                    #if HAVE_GCR
                     GCR_VERSION,
+                    #elif HAVE_GRANITE
                     GRANITE_VERSION,
                     LIBNOTIFY_VERSION,
-                    #if HAVE_UNIQUE
+                    #elif HAVE_UNIQUE
                     "libunique " UNIQUE_VERSION,
                     #else
                     "Sockets",
