--- trac/util/html.py.orig	2021-05-09 23:08:49 UTC
+++ trac/util/html.py
@@ -25,6 +25,10 @@ from html import entities
 from html.parser import HTMLParser
 
 from markupsafe import Markup, escape as escape_quotes
+try:
+    from markupsafe import soft_str as soft_unicode
+except ImportError:
+    from markupsafe import soft_unicode
 
 try:
     from babel.support import LazyProxy
