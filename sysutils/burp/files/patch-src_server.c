--- src/server.c.orig	2018-02-24 10:51:22 UTC
+++ src/server.c
@@ -543,7 +543,7 @@ static int do_backup_server(const char *basedir, const
 			working, current, currentdata,
 			finishing, cconf, client,
 			p1cntr, cntr);
-		if(!ret && cconf->keep>0)
+		if(!ret && *cconf->keep > 0)
 			ret=remove_old_backups(basedir, cconf, client);
 	}
 
