--- src/plugins/fts-solr/solr-connection.c.orig	2020-08-12 12:20:41 UTC
+++ src/plugins/fts-solr/solr-connection.c
@@ -103,7 +103,7 @@ int solr_connection_init(const struct fts_solr_setting
 		http_set.ssl = ssl_client_set;
 		http_set.debug = solr_set->debug;
 		http_set.rawlog_dir = solr_set->rawlog_dir;
-		solr_http_client = http_client_init(&http_set);
+		solr_http_client = http_client_init_private(&http_set);
 	}
 
 	*conn_r = conn;
