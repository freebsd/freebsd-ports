--- import/extract_ac3.c.orig	2011-11-19 16:50:27 UTC
+++ import/extract_ac3.c
@@ -334,7 +334,7 @@ static void pes_ac3_loop (void)
 FILE *fd;
 
 #define MAX_BUF 4096
-char audio[MAX_BUF];
+static char audio[MAX_BUF];
 
 
 /* from ac3scan.c */
