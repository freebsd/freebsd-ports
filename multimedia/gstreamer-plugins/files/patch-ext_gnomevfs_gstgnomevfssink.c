--- ext/gnomevfs/gstgnomevfssink.c.orig	Wed Apr 28 17:16:05 2004
+++ ext/gnomevfs/gstgnomevfssink.c	Wed Apr 28 17:16:20 2004
@@ -347,7 +347,7 @@
     }
     sink->own_handle = TRUE;
   } else if (!sink->handle) {
-    GST_ELEMENT_ERROR (sink, RESOURCE, FAILED, (_("No filename given")), NULL);
+    GST_ELEMENT_ERROR (sink, RESOURCE, FAILED, (_("No filename given")), (NULL));
     return FALSE;
   }
 
