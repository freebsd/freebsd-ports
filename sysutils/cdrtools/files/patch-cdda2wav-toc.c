--- cdda2wav/toc.c.original	Fri May 21 22:56:44 2004
+++ cdda2wav/toc.c	Mon Jan 16 13:54:30 2006
@@ -959,7 +959,7 @@
 					if (*target != NULL)
 						**target = '\0';
 				} else {
-					realloc(*target, strlen(*target) + clen - 1);
+					*target = realloc(*target, strlen(*target) + clen - 1);
 				}
 				if (*target != NULL) {
 					strcat((char *)*target, inbuff+ind+7);
@@ -994,7 +994,7 @@
 							if (global.tracktitle[tno] != NULL)
 								*(global.tracktitle[tno]) = '\0';
 						} else {
-							realloc(global.tracktitle[tno], strlen((char *)global.tracktitle[tno]) + p - q + 1 );
+							global.tracktitle[tno] = realloc(global.tracktitle[tno], strlen((char *)global.tracktitle[tno]) + p - q + 1 );
 						}
 						if (global.tracktitle[tno] != NULL) {
 							strcat((char *)global.tracktitle[tno], q+1);
