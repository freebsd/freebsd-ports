--- src/resolv.c.orig	Sat Apr 29 09:58:35 2006
+++ src/resolv.c	Mon May 29 00:54:06 2006
@@ -500,7 +500,7 @@
    */
   if (g_pethers_path == NULL)
     {
-      g_strdup_printf (g_pethers_path, "%s/%s",
+      g_pethers_path = g_strdup_printf ("%s/%s",
 	       get_home_dir (), EPATH_PERSONAL_ETHERS);
     }
 
