--- mail.c.orig	2026-08-30 20:07:40 UTC
+++ mail.c
@@ -338,7 +338,7 @@ newaddr:
 	ps->pos = 0;
 	addr = strdup(ps->addr);
 	if (addr == NULL)
-		errlog(EX_SOFTWARE, NULL);
+		errlog(EX_SOFTWARE, "strdup failed");
 
 	if (add_recp(queue, addr, EXPAND_WILDCARD) != 0)
 		errlogx(EX_DATAERR, "invalid recipient `%s'", addr);
