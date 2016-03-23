--- dma.c.orig	2016-02-07 12:41:49 UTC
+++ dma.c
@@ -340,7 +340,7 @@ retry:
 			exit(EX_SOFTWARE);
 		}
 		if (gettimeofday(&now, NULL) == 0 &&
-		    (now.tv_sec - st.st_mtim.tv_sec > MAX_TIMEOUT)) {
+		    (now.tv_sec - st.st_mtime > MAX_TIMEOUT)) {
 			snprintf(errmsg, sizeof(errmsg),
 				 "Could not deliver for the last %d seconds. Giving up.",
 				 MAX_TIMEOUT);
@@ -564,7 +564,7 @@ main(int argc, char **argv)
 skipopts:
 	if (logident_base == NULL)
 		logident_base = "dma";
-	setlogident(NULL);
+	setlogident("%s", logident_base);
 
 	act.sa_handler = sighup_handler;
 	act.sa_flags = 0;
@@ -596,7 +596,7 @@ skipopts:
 		errlog(EX_SOFTWARE, "could not parse aliases file `%s'", config.aliases);
 
 	if ((sender = set_from(&queue, sender)) == NULL)
-		errlog(EX_SOFTWARE, NULL);
+		errlog(EX_SOFTWARE, "set_from failed");
 
 	if (newspoolf(&queue) != 0)
 		errlog(EX_CANTCREAT, "can not create temp file in `%s'", config.spooldir);
