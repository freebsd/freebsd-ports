--- trackeywords/web_ui.py.orig	2009-09-09 13:18:34 UTC
+++ trackeywords/web_ui.py
@@ -80,7 +80,8 @@ class TracKeywordsComponent(core.Compone
 
     # changed to Genshi signature
     def post_process_request(self, req, template, data, content_type):
-        data['keywords'] = self._get_keywords()
+        if data is not None:
+            data['keywords'] = self._get_keywords()
         return (template, data, content_type)
 
     ### ITemplateProvider methods
