--- plaso/output/elastic.py.orig	2014-12-20 17:43:35 UTC
+++ plaso/output/elastic.py
@@ -81,6 +81,8 @@ class Elastic(output.LogOutputFormatter)
     elastic_port = getattr(config, 'elastic_port', 9200)
     self._elastic_db = pyelasticsearch.ElasticSearch(
         u'http://{0:s}:{1:d}'.format(elastic_host, elastic_port))
+    logging.getLogger('elasticsearch.trace').setLevel(logging.WARNING)
+    logging.getLogger('elasticsearch').setLevel(logging.WARNING)
 
     case_name = getattr(config, 'case_name', u'')
     document_type = getattr(config, 'document_type', u'')
