--- src/log.cc.orig	2018-08-28 11:26:42 UTC
+++ src/log.cc
@@ -72,7 +72,7 @@ int CommonLogParser::parse(char *logline, struct logbi
 			/* fire off a query with adns */
 			b->dns_query = new adns_query;
 			adns_submit(adns, ptr, adns_r_a,
-			    (adns_queryflags) NULL, NULL, b->dns_query);
+			    (adns_queryflags) 0, 0, b->dns_query);
 
 			b->ip_pos = im->insert(RESOLVING_STRING);
 			b->ip_hash = TTHash(RESOLVING_STRING);
