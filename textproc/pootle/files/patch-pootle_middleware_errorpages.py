--- pootle/middleware/errorpages.py.orig	2015-06-03 13:30:24 UTC
+++ pootle/middleware/errorpages.py
@@ -28,7 +28,7 @@ from django.http import (Http404, HttpRe
                          HttpResponseServerError)
 from django.template import RequestContext
 from django.template.loader import render_to_string
-from django.utils import simplejson
+import simplejson
 from django.utils.encoding import force_unicode
 from django.utils.translation import ugettext as _
 
