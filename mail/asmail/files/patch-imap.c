--- imap.c.orig	2007-02-27 10:19:38.000000000 -0800
+++ imap.c	2011-01-06 23:12:58.000000000 -0800
@@ -138,13 +138,18 @@
 
 	/* connection is open, let's log in */
 
-	sprintf(output, "A000 LOGIN %s %s\r\n", mb->user, mb->pass);
-   WRITE_OUTPUT;
+    sprintf(output, "A000 LOGIN %s %s\r\n", mb->user, mb->pass);
+    WRITE_OUTPUT;
+    while (1) {
 	WAITOK;
+	if (strncmp(input, "A000 ", 5)) /* allow for other tags/untagged */
+	    continue;
+
 	if ( strncmp(input, "A000 OK", 7) ) {
-		BYE(STAT_LOGIN);
+	    BYE(STAT_LOGIN);
 	}
 	return(STAT_IDLE);
+    }
 }
 
 
@@ -287,6 +292,7 @@
 					imap_checkmbox(mb, &s);
 			}
 		} else {
+			mb->status = STAT_RUN;
 			mb->status |= imap_login(mb, &s);
 			mb->status |= imap_checkmbox(mb, &s);
 			mb->status |= imap_goodbye(mb, &s);
