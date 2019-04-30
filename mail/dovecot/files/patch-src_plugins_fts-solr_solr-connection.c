--- src/plugins/fts-solr/solr-connection.c.orig	2019-04-30 12:25:06 UTC
+++ src/plugins/fts-solr/solr-connection.c
@@ -156,7 +156,7 @@ int solr_connection_init(const struct fts_solr_setting
 		http_set.ssl = ssl_client_set;
 		http_set.debug = solr_set->debug;
 		http_set.rawlog_dir = solr_set->rawlog_dir;
-		solr_http_client = http_client_init(&http_set);
+		solr_http_client = http_client_init_private(&http_set);
 	}
 
 	conn->xml_parser = XML_ParserCreate("UTF-8");
