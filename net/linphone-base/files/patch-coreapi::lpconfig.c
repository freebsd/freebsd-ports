--- coreapi/lpconfig.c.orig	Fri Mar 11 21:53:12 2005
+++ coreapi/lpconfig.c	Wed Mar 23 17:44:35 2005
@@ -266,8 +266,9 @@
 }
 
 int lp_config_sync(LpConfig *lpconfig){
+	FILE *file;
 	if (lpconfig->filename==NULL) return;
-	FILE *file=fopen(lpconfig->filename,"w");
+	file=fopen(lpconfig->filename,"w");
 	if (file==NULL){
 		g_warning("Could not write %s !",lpconfig->filename);
 		return -1;
