--- src/gmdns.c.orig	Sat Jun  5 23:06:29 2004
+++ src/gmdns.c	Sat Jun  5 23:07:20 2004
@@ -439,7 +439,7 @@
 
 	/* if there are no more listeners */
 	if (aq->listeners == NULL) {
-		g_message ("mdnsd_query (%s, %d, %p, %p)\n", name, type, NULL, NULL);
+		g_message ("mdnsd_query (%s, %d, %p, %p)\n", name, type, (void*)NULL, (void*)NULL);
 		/* stop the query */
 		mdnsd_query (GMDNS_MDNSD, (char*) name, type, NULL, NULL);
 
