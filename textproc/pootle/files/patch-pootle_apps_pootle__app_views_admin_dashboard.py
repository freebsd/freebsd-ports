--- pootle/apps/pootle_app/views/admin/dashboard.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/pootle_app/views/admin/dashboard.py
@@ -26,7 +26,7 @@ from django.core.cache import cache
 from django.http import HttpResponse
 from django.shortcuts import render_to_response
 from django.template import RequestContext
-from django.utils import simplejson
+import simplejson
 from django.utils.translation import ugettext as _
 
 from pootle import depcheck
