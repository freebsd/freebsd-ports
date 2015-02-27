--- src/or/connection_edge.c.orig	2015-02-26 16:49:50.952720442 -0500
+++ src/or/connection_edge.c	2015-02-26 16:35:52.411777582 -0500
@@ -1531,7 +1531,7 @@
   if (options->TransProxyType_parsed == TPT_PF_DIVERT)
     return destination_from_socket(conn, req);
 
-  if (options->TransProxyType_parsed == TPT_DEFAULT)
+  if (options->TransProxyType_parsed == TPT_DEFAULT || options->TransProxyType_parsed == TPT_IPFW)
     return destination_from_pf(conn, req);
 
   (void)conn;
