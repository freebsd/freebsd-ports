Add compatibility for Django 4.x

Obtained from:

https://patch-diff.githubusercontent.com/raw/Fantomas42/django-tagging/pull/23.patch

--- tagging/models.py.orig	2020-03-06 17:56:16 UTC
+++ tagging/models.py
@@ -5,7 +5,8 @@ from django.db import models
 from django.contrib.contenttypes.models import ContentType
 from django.db import connection
 from django.db import models
-from django.utils.encoding import smart_text
+from django.db.models.query_utils import Q
+from django.utils.encoding import smart_str
 from django.utils.translation import gettext_lazy as _
 
 from tagging import settings
@@ -155,8 +156,9 @@ class TagManager(models.Manager):
             filters = {}
 
         queryset = model._default_manager.filter()
-        for f in filters.items():
-            queryset.query.add_filter(f)
+        for k, v in filters.items():
+            # Add support for both Django 4 and inferior versions
+            queryset.query.add_q(Q((k, v)))
         usage = self.usage_for_queryset(queryset, counts, min_count)
 
         return usage
@@ -519,4 +521,4 @@ class TaggedItem(models.Model):
         verbose_name_plural = _('tagged items')
 
     def __str__(self):
-        return '%s [%s]' % (smart_text(self.object), smart_text(self.tag))
+        return '%s [%s]' % (smart_str(self.object), smart_str(self.tag))
