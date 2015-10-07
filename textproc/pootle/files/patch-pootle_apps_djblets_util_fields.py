--- pootle/apps/djblets/util/fields.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/djblets/util/fields.py
@@ -30,7 +30,7 @@ from datetime import datetime
 from django.conf import settings
 from django.core.serializers.json import DjangoJSONEncoder
 from django.db import models
-from django.utils import simplejson
+import simplejson
 from django.utils.encoding import smart_unicode
 
 
