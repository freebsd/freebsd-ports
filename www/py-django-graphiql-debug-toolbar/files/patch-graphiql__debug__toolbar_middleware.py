Add compatibility for py-django-debug-toolbar >= 4.4.6

If py-graphiql-debug-toolbar is used with py-django-debug-toolbar 4.4.6 or
newer, the following error is emitted:

[...]
  File "/usr/local/lib/python3.11/site-packages/graphiql_debug_toolbar/middleware.py", line 7, in <module>
      from debug_toolbar.middleware import _HTML_TYPES
  ImportError: cannot import name '_HTML_TYPES' from 'debug_toolbar.middleware' (/usr/local/lib/python3.11/site-packages/debug_toolbar/middleware.py)
[...]

This is because py-django-debugtoolbar "_HTML_TYPES" has been moved from
"debug_toolbar.middleware" to "debug_toolbar.utils" in the 4.4.6 release.

--- graphiql_debug_toolbar/middleware.py.orig	2021-08-28 21:44:07 UTC
+++ graphiql_debug_toolbar/middleware.py
@@ -4,7 +4,11 @@ from django.utils.encoding import force_str
 from django.template.loader import render_to_string
 from django.utils.encoding import force_str
 
-from debug_toolbar.middleware import _HTML_TYPES
+try:
+    from debug_toolbar.middleware import _HTML_TYPES
+except ImportError:
+    from debug_toolbar.utils import _HTML_TYPES
+
 from debug_toolbar.middleware import DebugToolbarMiddleware as BaseMiddleware
 from debug_toolbar.toolbar import DebugToolbar
 from graphene_django.views import GraphQLView
