--- src/install.c.orig	2004-08-24 04:03:44 UTC
+++ src/install.c
@@ -958,6 +958,8 @@ install_action_run(struct install_data *
 	av[ac++] = "SU_CMD=" SU_CMD;
 	av[ac++] = "-M";
 	av[ac++] = "FETCH_CMD=" FETCH_CMD;
+	av[ac++] = "-M";
+	av[ac++] = "DIALOG=gdialog";
 	av[ac++] = "-s";
 	av[ac++] = "-S";
 	av[ac++] = SU_CMD " '%s'";
@@ -971,6 +973,7 @@ install_action_run(struct install_data *
 	av[ac++] = "make";
 	av[ac++] = "SU_CMD=" SU_CMD;
 	av[ac++] = "FETCH_CMD=" FETCH_CMD;
+	av[ac++] = "DIALOG=gdialog";
 
 	if (iadp->ia_action == INSTACT_PACKAGE)
 	{
