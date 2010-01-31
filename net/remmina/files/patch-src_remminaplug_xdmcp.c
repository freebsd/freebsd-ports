--- src/remminaplug_xdmcp.c.orig	2010-01-21 00:08:01.000000000 +0800
+++ src/remminaplug_xdmcp.c	2010-01-30 21:45:32.000000000 +0800
@@ -237,6 +237,7 @@
         }
     }
     else
+#endif
     {
         if (!remmina_plug_xdmcp_start_xephyr (gp_xdmcp))
         {
@@ -244,7 +245,6 @@
             return FALSE;
         }
     }
-#endif
 
     gp_xdmcp->thread = 0;
     return TRUE;
