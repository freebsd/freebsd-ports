--- pootle/apps/pootle_misc/util.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/pootle_misc/util.py
@@ -25,7 +25,8 @@ from django.conf import settings
 from django.core.cache import cache
 from django.core.paginator import Paginator
 from django.http import HttpResponseBadRequest
-from django.utils import simplejson, timezone
+from django.utils import timezone
+import simplejson
 from django.utils.encoding import force_unicode, iri_to_uri
 from django.utils.functional import Promise
 
