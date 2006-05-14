--- src/install.c.orig	Sun Apr  2 14:09:25 2006
+++ src/install.c	Sun Apr  2 14:12:03 2006
@@ -958,6 +958,8 @@
 	av[ac++] = "SU_CMD=" SU_CMD;
 	av[ac++] = "-M";
 	av[ac++] = "FETCH_CMD=" FETCH_CMD;
+	av[ac++] = "-M";
+	av[ac++] = "DIALOG=gdialog";
 	av[ac++] = "-s";
 	av[ac++] = "-S";
 	av[ac++] = SU_CMD " '%s'";
@@ -971,6 +973,7 @@
 	av[ac++] = "make";
 	av[ac++] = "SU_CMD=" SU_CMD;
 	av[ac++] = "FETCH_CMD=" FETCH_CMD;
+	av[ac++] = "DIALOG=gdialog";
 
 	if (iadp->ia_action == INSTACT_PACKAGE)
 	{
