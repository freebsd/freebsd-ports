--- convert.c.orig	Sun Jan 30 13:34:16 2005
+++ convert.c	Sun Jan 30 13:35:36 2005
@@ -341,7 +341,7 @@
 				while(w2) {
 					tmp = word_string (w2);
 					if (tmp && tmp[0] != '\\')
-						strcat(name,tmp);
+						strncat(name,tmp,sizeof(name)-strlen(name)-1);
 
 					w2=w2->next;
 				}
