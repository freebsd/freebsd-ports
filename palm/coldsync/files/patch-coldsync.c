--- src/coldsync.c.ORIG	Fri Apr 18 22:59:58 2003
+++ src/coldsync.c	Fri Apr 18 23:10:57 2003
@@ -622,7 +622,7 @@
 
 	time(&now);
 	Verbose(1, _("Sync for %s at %s"),
-		(pda->name == NULL ? "unnamed PDA" : pda->name),
+		(pda == NULL || pda->name == NULL ? "unnamed PDA" : pda->name),
 		ctime(&now));
 
 	/* See if the userid matches. */
