--- tempita/__init__.py.orig	2013-12-17 03:59:28 UTC
+++ tempita/__init__.py
@@ -32,10 +32,10 @@ If there are syntax errors ``TemplateError`` will be r
 import re
 import sys
 import cgi
-from urllib import quote as url_quote
+from urllib.parse import quote as url_quote
 import os
 import tokenize
-from cStringIO import StringIO
+from io import StringIO
 from tempita._looper import looper
 from tempita.compat3 import bytes, basestring_, next, is_unicode, coerce_text
 
@@ -101,7 +101,7 @@ class Template(object):
             delimiters = (self.default_namespace['start_braces'],
                           self.default_namespace['end_braces'])
         else:
-            assert len(delimiters) == 2 and all([isinstance(delimeter, basestring)
+            assert len(delimiters) == 2 and all([isinstance(delimeter, str)
                                                  for delimeter in delimiters])
             self.default_namespace = self.__class__.default_namespace.copy()
             self.default_namespace['start_braces'] = delimiters[0]
@@ -196,7 +196,7 @@ class Template(object):
                 position=None, name=self.name)
         templ = self.get_template(inherit_template, self)
         self_ = TemplateObject(self.name)
-        for name, value in defs.iteritems():
+        for name, value in defs.items():
             setattr(self_, name, value)
         self_.body = body
         ns = ns.copy()
@@ -292,7 +292,7 @@ class Template(object):
         try:
             try:
                 value = eval(code, self.default_namespace, ns)
-            except SyntaxError, e:
+            except SyntaxError as e:
                 raise SyntaxError(
                     'invalid syntax in expression: %s' % code)
             return value
@@ -304,12 +304,12 @@ class Template(object):
             else:
                 arg0 = coerce_text(e)
             e.args = (self._add_line_info(arg0, pos),)
-            raise exc_info[0], e, exc_info[2]
+            raise exc_info[0](e).with_traceback(exc_info[2])
 
     def _exec(self, code, ns, pos):
         __traceback_hide__ = True
         try:
-            exec code in self.default_namespace, ns
+            exec(code, self.default_namespace, ns)
         except:
             exc_info = sys.exc_info()
             e = exc_info[1]
@@ -317,7 +317,7 @@ class Template(object):
                 e.args = (self._add_line_info(e.args[0], pos),)
             else:
                 e.args = (self._add_line_info(None, pos),)
-            raise exc_info[0], e, exc_info[2]
+            raise exc_info[0](e).with_traceback(exc_info[2])
 
     def _repr(self, value, pos):
         __traceback_hide__ = True
@@ -326,7 +326,7 @@ class Template(object):
                 return ''
             if self._unicode:
                 try:
-                    value = unicode(value)
+                    value = str(value)
                 except UnicodeDecodeError:
                     value = bytes(value)
             else:
@@ -339,7 +339,7 @@ class Template(object):
             exc_info = sys.exc_info()
             e = exc_info[1]
             e.args = (self._add_line_info(e.args[0], pos),)
-            raise exc_info[0], e, exc_info[2]
+            raise exc_info[0](e).with_traceback(exc_info[2])
         else:
             if self._unicode and isinstance(value, bytes):
                 if not self.default_encoding:
@@ -348,7 +348,7 @@ class Template(object):
                         '(no default_encoding provided)' % value)
                 try:
                     value = value.decode(self.default_encoding)
-                except UnicodeDecodeError, e:
+                except UnicodeDecodeError as e:
                     raise UnicodeDecodeError(
                         e.encoding,
                         e.object,
@@ -385,7 +385,7 @@ def paste_script_template_renderer(content, vars, file
 class bunch(dict):
 
     def __init__(self, **kw):
-        for name, value in kw.iteritems():
+        for name, value in kw.items():
             setattr(self, name, value)
 
     def __setattr__(self, name, value):
@@ -408,7 +408,7 @@ class bunch(dict):
 
     def __repr__(self):
         items = [
-            (k, v) for k, v in self.iteritems()]
+            (k, v) for k, v in self.items()]
         items.sort()
         return '<%s %s>' % (
             self.__class__.__name__,
@@ -461,7 +461,7 @@ def url(v):
 
 
 def attr(**kw):
-    kw = list(kw.iteritems())
+    kw = list(kw.items())
     kw.sort()
     parts = []
     for name, value in kw:
@@ -543,7 +543,7 @@ class TemplateDef(object):
         values = {}
         sig_args, var_args, var_kw, defaults = self._func_signature
         extra_kw = {}
-        for name, value in kw.iteritems():
+        for name, value in kw.items():
             if not var_kw and name not in sig_args:
                 raise TypeError(
                     'Unexpected argument %s' % name)
@@ -566,7 +566,7 @@ class TemplateDef(object):
                 raise TypeError(
                     'Extra position arguments: %s'
                     % ', '.join(repr(v) for v in args))
-        for name, value_expr in defaults.iteritems():
+        for name, value_expr in defaults.items():
             if name not in values:
                 values[name] = self._template._eval(
                     value_expr, self._ns, self._pos)
@@ -612,7 +612,7 @@ class _Empty(object):
         return 'Empty'
 
     def __unicode__(self):
-        return u''
+        return ''
 
     def __iter__(self):
         return iter(())
@@ -1156,7 +1156,7 @@ def fill_command(args=None):
         vars.update(os.environ)
     for value in args:
         if '=' not in value:
-            print('Bad argument: %r' % value)
+            print(('Bad argument: %r' % value))
             sys.exit(2)
         name, value = value.split('=', 1)
         if name.startswith('py:'):
