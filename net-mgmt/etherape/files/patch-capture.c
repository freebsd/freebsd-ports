--- src/capture.c.orig	Sat Apr 29 09:58:35 2006
+++ src/capture.c	Mon May 29 01:14:23 2006
@@ -464,10 +464,13 @@
       return FALSE;
     }
 
-  /* preparing protocol summary and nodes/links catalogs */
-  protocol_summary_open();
-  nodes_catalog_open();
-  links_catalog_open();
+  if (status != PAUSE)
+    {
+      /* preparing protocol summary and nodes/links catalogs */
+      protocol_summary_open();
+      nodes_catalog_open();
+      links_catalog_open();
+    }
 
   /*
    * See pause_capture for an explanation of why we don't always
