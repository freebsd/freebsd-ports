--- src/main.c.orig	Sun Sep 29 14:07:48 2002
+++ src/main.c	Sun Sep 29 14:08:52 2002
@@ -1269,6 +1269,7 @@
 
 	char *virtual_share_path=NULL;
 
+	hide_absolute=1;
 	disp_msg(INFO_MSG,NULL,"Direct Connect Text Client v" VERSION ,NULL);
 
 	if(argc==1)
