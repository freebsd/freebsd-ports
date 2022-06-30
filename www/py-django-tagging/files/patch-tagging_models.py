--- tagging/models.py.orig	2022-04-11 10:40:39 UTC
+++ tagging/models.py
@@ -5,6 +5,7 @@ from django.contrib.contenttypes.fields import Generic
 from django.contrib.contenttypes.models import ContentType
 from django.db import connection
 from django.db import models
+from django.db.models.query_utils import Q
 from django.utils.encoding import smart_text
 from django.utils.translation import gettext_lazy as _
 
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
