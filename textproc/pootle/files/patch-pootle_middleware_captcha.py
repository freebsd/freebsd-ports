--- pootle/middleware/captcha.py.orig	2015-06-03 13:30:24 UTC
+++ pootle/middleware/captcha.py
@@ -29,7 +29,7 @@ from django.conf import settings
 from django.http import HttpResponse
 from django.shortcuts import render_to_response
 from django.template import loader, RequestContext
-from django.utils import simplejson
+import simplejson
 from django.utils.translation import ugettext as _
 
 
