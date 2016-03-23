--- mail.c.orig	2016-02-07 12:41:49 UTC
+++ mail.c
@@ -333,7 +333,7 @@ newaddr:
 	ps->pos = 0;
 	addr = strdup(ps->addr);
 	if (addr == NULL)
-		errlog(EX_SOFTWARE, NULL);
+		errlog(EX_SOFTWARE, "strdup failed");
 
 	if (add_recp(queue, addr, EXPAND_WILDCARD) != 0)
 		errlogx(EX_DATAERR, "invalid recipient `%s'", addr);
