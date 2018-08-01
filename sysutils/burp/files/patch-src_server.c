server.c:546:25: error: ordered comparison between pointer and zero ('struct strlist **' and 'int')
                if(!ret && cconf->keep>0)
                           ~~~~~~~~~~~^~

--- src/server.c.orig	2018-08-01 13:34:56 UTC
+++ src/server.c
@@ -543,7 +543,7 @@ static int do_backup_server(const char *basedir, const
 			working, current, currentdata,
 			finishing, cconf, client,
 			p1cntr, cntr);
-		if(!ret && cconf->keep>0)
+		if(!ret && cconf->keep != NULL)
 			ret=remove_old_backups(basedir, cconf, client);
 	}
 
