--- ./trac/web/main.py.orig	2010-06-13 20:36:24.000000000 +0000
+++ ./trac/web/main.py	2010-10-12 06:14:47.022524485 +0000
@@ -26,10 +26,6 @@
 from pprint import pformat, pprint
 import sys
 
-try:
-    from babel import Locale
-except ImportError:
-    Locale = None
 from genshi.core import Markup
 from genshi.builder import Fragment, tag
 from genshi.output import DocType
@@ -48,7 +44,8 @@
 from trac.util.concurrency import threading
 from trac.util.datefmt import format_datetime, http_date, localtz, timezone
 from trac.util.text import exception_to_unicode, shorten_line, to_unicode
-from trac.util.translation import safefmt, tag_, _
+from trac.util.translation import _, get_negotiated_locale, has_babel, \
+                                  safefmt, tag_
 from trac.web.api import *
 from trac.web.chrome import Chrome
 from trac.web.clearsilver import HDFWrapper
@@ -150,6 +147,11 @@
     default_timezone = Option('trac', 'default_timezone', '',
         """The default timezone to use""")
 
+    default_language = Option('trac', 'default_language', '',
+        """The preferred language to use if no user preference has been set.
+        (''since 0.12.1'')
+        """)
+
     # Public API
 
     def authenticate(self, req):
@@ -302,16 +304,12 @@
             return FakeSession()
 
     def _get_locale(self, req):
-        if Locale:
-            available = [locale_id.replace('_', '-') for locale_id in
-                         translation.get_available_locales()]
-
-            preferred = req.session.get('language', req.languages)
-            if not isinstance(preferred, list):
-                preferred = [preferred]
-            negotiated = Locale.negotiate(preferred, available, sep='-')
-            self.log.debug("Negotiated locale: %s -> %s",
-                           preferred, negotiated)
+        if has_babel:
+            preferred = req.session.get('language')
+            default = self.env.config.get('trac', 'default_language', '')
+            negotiated = get_negotiated_locale([preferred, default] +
+                                               req.languages)
+            self.log.debug("Negotiated locale: %s -> %s", preferred, negotiated)
             return negotiated
 
     def _get_timezone(self, req):
