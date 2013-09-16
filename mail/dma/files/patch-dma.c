--- dma.c.orig	2013-08-22 10:56:28.000000000 +0000
+++ dma.c	2013-08-22 11:03:59.000000000 +0000
@@ -343,7 +343,7 @@ retry:
 			exit(1);
 		}
 		if (gettimeofday(&now, NULL) == 0 &&
-		    (now.tv_sec - st.st_mtim.tv_sec > MAX_TIMEOUT)) {
+		    (now.tv_sec - st.st_mtime > MAX_TIMEOUT)) {
 			snprintf(errmsg, sizeof(errmsg),
 				 "Could not deliver for the last %d seconds. Giving up.",
 				 MAX_TIMEOUT);
@@ -560,7 +560,7 @@ main(int argc, char **argv)
 skipopts:
 	if (logident_base == NULL)
 		logident_base = "dma";
-	setlogident(NULL);
+	setlogident("%s", logident_base);
 
 	act.sa_handler = sighup_handler;
 	act.sa_flags = 0;
@@ -598,7 +598,7 @@ skipopts:
 		errlog(1, "can not read aliases file `%s'", config.aliases);
 
 	if ((sender = set_from(&queue, sender)) == NULL)
-		errlog(1, NULL);
+		errlog(1, "set_from failed");
 
 	if (newspoolf(&queue) != 0)
 		errlog(1, "can not create temp file in `%s'", config.spooldir);
