--- vtysh/vtysh.c.orig	2017-08-09 12:56:09.000000000 +0200
+++ vtysh/vtysh.c	2017-08-22 22:04:36.068181000 +0200
@@ -249,7 +249,7 @@
 	if (pager_defined)
 		vtysh_pager_name = strdup(pager_defined);
 	else
-		vtysh_pager_name = strdup("more");
+		vtysh_pager_name = strdup("cat");
 }
 
 /* Command execution over the vty interface. */
