--- trac/util/html.py.orig	2021-05-09 23:08:49 UTC
+++ trac/util/html.py
@@ -24,7 +24,7 @@ import sys
 from html import entities
 from html.parser import HTMLParser
 
-from markupsafe import Markup, escape as escape_quotes
+from markupsafe import Markup, escape as escape_quotes, soft_unicode
 
 try:
     from babel.support import LazyProxy
