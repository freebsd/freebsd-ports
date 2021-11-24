--- trac/util/text.py.orig	2021-05-09 23:08:49 UTC
+++ trac/util/text.py
@@ -22,6 +22,7 @@ import base64
 import configparser
 import locale
 import os
+import pkg_resources
 import re
 import sys
 import textwrap
@@ -43,6 +44,11 @@ del Empty # shouldn't be used outside of Trac core
 
 # -- Jinja2
 
+_jinja2_ver = pkg_resources.parse_version(jinja2.__version__)
+_jinja2_exts = ['jinja2.ext.do', 'jinja2.ext.i18n']
+if _jinja2_ver < pkg_resources.parse_version('3'):
+    _jinja2_exts.append('jinja2.ext.with_')
+
 def jinja2env(**kwargs):
     """Creates a Jinja2 ``Environment`` configured with Trac conventions.
 
@@ -65,7 +71,7 @@ def jinja2env(**kwargs):
         line_comment_prefix='##',
         trim_blocks=True,
         lstrip_blocks=True,
-        extensions=['jinja2.ext.do', 'jinja2.ext.i18n', 'jinja2.ext.with_'],
+        extensions=list(_jinja2_exts),
         finalize=filterout_none,
         autoescape=autoescape_extensions,
     )
