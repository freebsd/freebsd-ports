--- tools/gst-inspect.c.orig	Mon May 24 12:12:28 2004
+++ tools/gst-inspect.c	Fri Jul  2 23:49:02 2004
@@ -797,7 +797,6 @@
       g_free (indent);
     }
 
-    g_free (query);
     if (found_signals) {
       g_slist_foreach (found_signals, (GFunc) g_free, NULL);
       g_slist_free (found_signals);
