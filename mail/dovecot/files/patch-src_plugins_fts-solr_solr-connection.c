--- src/plugins/fts-solr/solr-connection.c.orig	2019-01-02 22:12:57 UTC
+++ src/plugins/fts-solr/solr-connection.c
@@ -156,7 +156,7 @@ int solr_connection_init(const char *url,
 		http_set.request_timeout_msecs = 60*1000;
 		http_set.ssl = ssl_client_set;
 		http_set.debug = debug;
-		solr_http_client = http_client_init(&http_set);
+		solr_http_client = http_client_init_private(&http_set);
 	}
 
 	conn->xml_parser = XML_ParserCreate("UTF-8");
