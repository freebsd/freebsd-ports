[FDclone-users:00997]
--- system.c.orig	2012-06-30 00:00:00.000000000 +0900
+++ system.c	2012-07-16 19:12:29.380468959 +0900
@@ -2769,7 +2769,7 @@
 	if (trapok >= 0) trapok = 0;
 
 # ifndef	NOJOB
-	if (mypid == orgpgrp) {
+	if (mypid == orgpgrp && (childpgrp < (p_id_t)0 || pid == childpgrp)) {
 		VOID_C gettermio(orgpgrp, jobok);
 #  ifdef	FD
 		checkscreen(-1, -1);
