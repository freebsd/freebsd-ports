--- src/npw-player.c.orig	2011-06-30 23:18:57.000000000 -0400
+++ src/npw-player.c	2014-02-10 15:02:58.000000000 -0500
@@ -25,7 +25,6 @@
 #include <unistd.h>
 #include <glib.h>
 #include <glib/gstdio.h>
-#include <glib/gthread.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkx.h>
 #include <gdk/gdkkeysyms.h>
@@ -1233,6 +1232,7 @@
     return NULL;
 
   curl_easy_setopt (handle, CURLOPT_URL, url);
+  curl_easy_setopt (handle, CURLOPT_NOSIGNAL, 1);
   curl_easy_setopt (handle, CURLOPT_WRITEFUNCTION, on_stream_read_nothing_cb);
   curl_easy_setopt (handle, CURLOPT_FILETIME, 1);
   curl_easy_setopt (handle, CURLOPT_TIMECONDITION, CURL_TIMECOND_LASTMOD);
@@ -1626,6 +1626,7 @@
 
   CURL * const handle = pstream->curl_handle;
   curl_easy_setopt (handle, CURLOPT_URL, pstream->np_stream->url);
+  curl_easy_setopt (handle, CURLOPT_NOSIGNAL, 1);
   curl_easy_setopt (handle, CURLOPT_WRITEFUNCTION, on_stream_read_cb);
   curl_easy_setopt (handle, CURLOPT_WRITEDATA, pstream);
   curl_easy_setopt (handle, CURLOPT_PRIVATE, pstream);
@@ -2667,7 +2668,11 @@
     }
 
   if (g_backend == BACKEND_GTK)
-    gtk_main ();
+    {
+      gdk_threads_enter ();
+      gtk_main ();
+      gdk_threads_leave ();
+    }
 
   for (i = 0; i < plugin_descs->len; i++)
     {
