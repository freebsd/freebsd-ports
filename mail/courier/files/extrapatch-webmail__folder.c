--- webmail/folder.c.orig	Sun Jul 23 00:09:04 2006
+++ webmail/folder.c	Sat Dec  9 22:23:23 2006
@@ -287,7 +287,7 @@
 			(unsigned long)pos);
 		return;
 	    }
-	    
+{
 	    char *cur = malloc(strlen(deldir)+5);
 	    strcpy(cur, deldir);
 	    strcat(cur, "/cur");
@@ -298,7 +298,7 @@
 	    maildir_info_destroy(&minfo);
 	    free(deldir);
 	    free(cur);
-	    
+}
 	}
 	else if (*cgi("cmdmove"))
 	{
