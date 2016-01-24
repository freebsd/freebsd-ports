--- plaso/output/elastic.py.orig	2015-12-31 17:37:07 UTC
+++ plaso/output/elastic.py
@@ -135,6 +135,8 @@ class ElasticSearchOutputModule(interfac
     """
     self._elastic_db = pyelasticsearch.ElasticSearch(
         u'http://{0:s}:{1:d}'.format(elastic_host, elastic_port))
+    logging.getLogger('elasticsearch.trace').setLevel(logging.WARNING)
+    logging.getLogger('elasticsearch').setLevel(logging.WARNING)
 
   def WriteEventBody(self, event_object):
     """Writes the body of an event object to the output.
