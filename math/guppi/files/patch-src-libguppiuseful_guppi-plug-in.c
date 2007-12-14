--- src/libguppiuseful/guppi-plug-in.c.orig	2007-12-13 15:26:58.000000000 +0100
+++ src/libguppiuseful/guppi-plug-in.c	2007-12-13 15:28:52.000000000 +0100
@@ -47,7 +47,7 @@
 
   guppi_finalized (obj);
 
-  guppi_free0 ((gpointer)pi->load_path);
+  guppi_free0 (pi->load_path);
 
   if (parent_class->finalize)
     parent_class->finalize (obj);
