--- sitemap_gen.py.orig	2007-07-19 03:33:30 UTC
+++ sitemap_gen.py
@@ -1799,7 +1799,7 @@ class Sitemap(xml.sax.handler.ContentHandler):
     if self._sitemap_type == 'news':
       sitemap_index_header = NEWS_SITEMAP_HEADER
     else:
-      sitemap__index_header = GENERAL_SITEMAP_HEADER
+      sitemap_index_header = GENERAL_SITEMAP_HEADER
  
     # Make a lastmod time
     lastmod = TimestampISO8601(time.time())
