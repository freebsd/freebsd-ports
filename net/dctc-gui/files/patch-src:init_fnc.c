--- src/init_fnc.c.orig	Thu Nov 22 02:15:54 2001
+++ src/init_fnc.c	Thu Nov 22 02:16:04 2001
@@ -376,7 +376,7 @@
 		gtk_clist_freeze(GTK_CLIST(rhcw));
 		gtk_clist_clear(GTK_CLIST(rhcw));
 
-		f=popen("hublist","r");
+		f=popen("dc_hublist","r");
 		if(f!=NULL)
 		{
 			char *ent[4];
