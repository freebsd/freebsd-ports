--- tools/gst-inspect.c.orig	Wed Jun 30 01:48:58 2004
+++ tools/gst-inspect.c	Wed Jun 30 01:49:18 2004
@@ -799,7 +799,6 @@
 
     g_free (query);
     if (found_signals) {
-      g_slist_foreach (found_signals, (GFunc) g_free, NULL);
       g_slist_free (found_signals);
     }
   }
