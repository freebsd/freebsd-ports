--- mail.c.orig	2020-02-05 10:59:09 UTC
+++ mail.c
@@ -335,7 +335,7 @@ newaddr:
 	ps->pos = 0;
 	addr = strdup(ps->addr);
 	if (addr == NULL)
-		errlog(EX_SOFTWARE, NULL);
+		errlog(EX_SOFTWARE, "strdup failed");
 
 	if (add_recp(queue, addr, EXPAND_WILDCARD) != 0)
 		errlogx(EX_DATAERR, "invalid recipient `%s'", addr);
