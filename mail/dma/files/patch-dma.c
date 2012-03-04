--- dma.c.orig	2012-01-28 22:36:55.000000000 +0000
+++ dma.c	2012-01-28 22:46:06.000000000 +0000
@@ -332,7 +332,7 @@ retry:
 			exit(1);
 		}
 		if (gettimeofday(&now, NULL) == 0 &&
-		    (now.tv_sec - st.st_mtim.tv_sec > MAX_TIMEOUT)) {
+		    (now.tv_sec - st.st_mtime > MAX_TIMEOUT)) {
 			snprintf(errmsg, sizeof(errmsg),
 				 "Could not deliver for the last %d seconds. Giving up.",
 				 MAX_TIMEOUT);
@@ -534,7 +535,7 @@ main(int argc, char **argv)
 skipopts:
 	if (logident_base == NULL)
 		logident_base = "dma";
-	setlogident(NULL);
+	setlogident(logident_base);
 
 	act.sa_handler = sighup_handler;
 	act.sa_flags = 0;
@@ -571,7 +572,7 @@ skipopts:
 		errlog(1, "can not read aliases file `%s'", config.aliases);
 
 	if ((sender = set_from(&queue, sender)) == NULL)
-		errlog(1, NULL);
+		errlog(1, "set_from failed");
 
 	if (newspoolf(&queue) != 0)
 		errlog(1, "can not create temp file");
