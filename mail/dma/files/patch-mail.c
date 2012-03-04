--- ./mail.c.orig	2012-01-03 13:54:05.000000000 +0000
+++ ./mail.c	2012-01-24 22:57:41.000000000 +0000
@@ -332,7 +332,7 @@
 	ps->pos = 0;
 	addr = strdup(ps->addr);
 	if (addr == NULL)
-		errlog(1, NULL);
+		errlog(1, "strdup failed");
 
 	if (add_recp(queue, addr, EXPAND_WILDCARD) != 0)
 		errlogx(1, "invalid recipient `%s'", addr);
