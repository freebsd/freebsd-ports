--- trackeywords/web_ui.py.orig	2009-09-09 17:18:34.000000000 +0400
+++ trackeywords/web_ui.py	2010-04-05 11:32:50.000000000 +0400
@@ -80,7 +80,8 @@
 
     # changed to Genshi signature
     def post_process_request(self, req, template, data, content_type):
-        data['keywords'] = self._get_keywords()
+        if data is not None:
+            data['keywords'] = self._get_keywords()
         return (template, data, content_type)
 
     ### ITemplateProvider methods
