--- ./trac/util/translation.py.orig	2010-06-13 20:36:24.000000000 +0000
+++ ./trac/util/translation.py	2010-10-12 06:14:47.021523796 +0000
@@ -101,8 +101,10 @@
     def dungettext(self, domain, singular, plural, num):
         return self.ungettext(singular, plural, num)
 
+has_babel = False
 
 try:
+    from babel import Locale
     from babel.support import LazyProxy, Translations
 
     class TranslationsProxy(object):
@@ -329,6 +331,14 @@
                 in pkg_resources.resource_listdir('trac', 'locale')
                 if '.' not in dirname]
 
+    def get_negotiated_locale(preferred_locales):
+        def normalize(locale_ids):
+            return [id.replace('_', '-') for id in locale_ids if id]
+        return Locale.negotiate(normalize(preferred_locales),
+                                normalize(get_available_locales()), sep='-')
+        
+    has_babel = True
+
 except ImportError: # fall back on 0.11 behavior, i18n functions are no-ops
     gettext = _ = gettext_noop
     dgettext = dgettext_noop
@@ -358,3 +368,6 @@
 
     def get_available_locales():
         return []
+
+    def get_negotiated_locale(preferred=None, default=None):
+        return None
