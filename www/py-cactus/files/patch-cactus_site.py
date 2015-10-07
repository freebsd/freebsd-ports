--- cactus/site.py.orig	2015-03-22 19:28:26 UTC
+++ cactus/site.py
@@ -7,8 +7,11 @@ import traceback
 import socket
 
 import django.conf
-from django.template.loader import add_to_builtins
-
+# BACKPORT https://github.com/koenbok/Cactus/pull/106
+try:
+    from django.template.loader import add_to_builtins
+except ImportError: # Django < 1.8
+    from django.template import add_to_builtins
 from cactus import ui as ui_module
 from cactus.config.router import ConfigRouter
 from cactus.deployment import get_deployment_engine_class
@@ -138,9 +141,10 @@ class Site(SiteCompatibilityLayer):
         to look for included templates.
         """
 
+# BACKPORT https://github.com/jezdez/django-hosts/issues/31
         settings = {
             "TEMPLATE_DIRS": [self.template_path, self.page_path],
-            "INSTALLED_APPS": ['django.contrib.markup'],
+            "INSTALLED_APPS": ['django_markwhat'],
         }
 
         if self.locale is not None:
