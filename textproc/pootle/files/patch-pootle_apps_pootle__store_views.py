--- pootle/apps/pootle_store/views.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/pootle_store/views.py
@@ -35,7 +35,8 @@ from django.shortcuts import get_object_
 from django.template import loader, RequestContext
 from django.utils.translation import to_locale, ugettext as _
 from django.utils.translation.trans_real import parse_accept_lang_header
-from django.utils import simplejson, timezone
+from django.utils import timezone
+import simplejson
 from django.utils.encoding import iri_to_uri
 from django.views.decorators.cache import never_cache
 from django.views.decorators.http import require_POST
