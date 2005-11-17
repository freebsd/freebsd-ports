--- synonym.c.orig	Mon Jan 19 21:20:30 2004
+++ synonym.c	Thu Nov 17 15:27:10 2005
@@ -512,11 +512,6 @@
 	}
 	if(delete_email)
 		return SMFIS_DISCARD;
-	if(add_copy)
-	{
-		copyto_list[strlen(copyto_list)-2]='\0';
-		smfi_addheader(ctx, "X-Synonym", copyto_list);
-	}
 	return SMFIS_CONTINUE;
 
 }
