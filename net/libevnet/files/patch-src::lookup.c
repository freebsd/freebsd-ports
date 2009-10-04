--- src/lookup.c.orig	2009-10-04 10:13:19.191192582 +0800
+++ src/lookup.c	2009-10-04 10:15:44.531364833 +0800
@@ -2037,7 +2037,7 @@
 } /* lookup_additional_query() */
 
 
-static void lookup_catch_ares(void *, int, unsigned char *, int);
+static void lookup_catch_ares(void *, int, int, unsigned char *, int);
 
 static void lookup_issue_query(struct lookup *l, struct lookup_query *q, const char *qname, size_t qnamelen, int rtype) {
 	struct ares_channel *c;
@@ -2052,7 +2052,7 @@
 	q->channel	= c;
 
 	if (l->opts.query_max != 0 && q->live_queries_made >= l->opts.query_max) {
-		lookup_catch_ares(q, ARES_ENODATA, NULL, 0);
+		lookup_catch_ares(q, ARES_ENODATA, 0, NULL, 0);
 	} else {
 		++q->live_queries_made;
 		ares_query(c->channel, qname, C_IN, lookup_rtype2arpa(rtype), lookup_catch_ares, q);
@@ -2708,7 +2708,7 @@
 } /* lookup_process() */
 
 
-static void lookup_catch_ares(void *l_, int ares_errno, unsigned char *abuf, int alen) {
+static void lookup_catch_ares(void *l_, int ares_errno, int timeouts, unsigned char *abuf, int alen) {
 	int lookup_errno	= LOOKUP_ESUCCESS;
 	struct lookup_query *q;
 	struct lookup *l;
