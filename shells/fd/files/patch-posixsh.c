[FDclone-users:00997]
--- posixsh.c.orig	2012-06-30 00:00:00.000000000 +0900
+++ posixsh.c	2012-07-16 19:12:29.376464809 +0900
@@ -112,8 +112,7 @@
 	int ret;
 	sigmask_t mask, omask;
 
-	if (ttypgrp < (p_id_t)0 || pgrp < (p_id_t)0 || pgrp == ttypgrp)
-		return(0);
+	if (ttypgrp < (p_id_t)0 || pgrp < (p_id_t)0) return(0);
 	else if (!job) {
 		ttypgrp = pgrp;
 		return(0);
