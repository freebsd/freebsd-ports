--- vtysh/vtysh.c.orig	2017-06-27 14:48:26 UTC
+++ vtysh/vtysh.c
@@ -261,7 +261,7 @@ vtysh_pager_init (void)
   if (pager_defined)
     vtysh_pager_name = strdup (pager_defined);
   else
-    vtysh_pager_name = strdup ("more");
+    vtysh_pager_name = strdup ("cat");
 }
 
 /* Command execution over the vty interface. */
