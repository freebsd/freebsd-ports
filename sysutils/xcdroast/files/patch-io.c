--- io.c.orig	Fri May 17 17:12:28 2002
+++ io.c	Fri May 17 17:12:44 2002
@@ -8492,7 +8492,8 @@
 			return 1;
 		} else {
 			/* create command to create new group */
-			g_snprintf(tmp,MAXLINE,"%s %s\n", GROUPADD, NONROOTMODEGROUP);
+
+			g_snprintf(tmp,MAXLINE,"%s groupadd -n %s\n", GROUPADD, NONROOTMODEGROUP);
 			strcat(ret,tmp);
 		}	
 	 }
