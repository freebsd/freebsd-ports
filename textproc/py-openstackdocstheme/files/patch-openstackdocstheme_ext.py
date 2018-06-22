--- openstackdocstheme/ext.py.orig	2018-03-29 20:08:16 UTC
+++ openstackdocstheme/ext.py
@@ -95,13 +95,13 @@ def _html_page_context(app, pagename, te
     global _html_context_data
     if _html_context_data is None:
         _html_context_data = {}
-        try:
-            _html_context_data['gitsha'] = subprocess.check_output(
-                ['git', 'rev-parse', 'HEAD'],
-            ).decode('utf-8').strip()
-        except Exception:
-            logger.warning('Cannot get gitsha from git repository.')
-            _html_context_data['gitsha'] = 'unknown'
+        #try:
+        #    _html_context_data['gitsha'] = subprocess.check_output(
+        #        ['git', 'rev-parse', 'HEAD'],
+        #    ).decode('utf-8').strip()
+        #except Exception:
+        #    logger.warning('Cannot get gitsha from git repository.')
+        _html_context_data['gitsha'] = 'unknown'
 
         doc_path = _get_doc_path(app)
         repo_name = app.config.repository_name
