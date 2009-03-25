--- src/mcd-debug.c.orig	2009-03-24 23:45:42.000000000 -0400
+++ src/mcd-debug.c	2009-03-24 23:46:43.000000000 -0400
@@ -119,7 +119,7 @@ void mcd_debug_init ()
 	mc_debug = atoi (mc_debug_str);
 }
 
-inline gint mcd_debug_get_level ()
+gint mcd_debug_get_level ()
 {
     return mc_debug;
 }
