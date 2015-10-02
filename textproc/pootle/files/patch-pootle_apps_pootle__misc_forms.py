--- pootle/apps/pootle_misc/forms.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/pootle_misc/forms.py
@@ -79,7 +79,7 @@ def make_search_form(*args, **kwargs):
 
         if sparams_cookie:
             import urllib
-            from django.utils import simplejson
+            import simplejson
 
             initial_sparams = simplejson.loads(urllib.unquote(sparams_cookie))
             if isinstance(initial_sparams, dict):
