Backported from fixes contained in http://trac.edgewall.org/ticket/11345

--- trac/util/translation.py.orig
+++ trac/util/translation.py
@@ -150,6 +150,6 @@
                 t = self._null_translations
             else:
-                t.add(Translations.load(locale_dir, locale or 'en_US',
-                                        'tracini'))
+                self._add(t, Translations.load(locale_dir, locale or 'en_US',
+                                               'tracini'))
                 if env_path:
                     with self._plugin_domains_lock:
@@ -157,5 +157,6 @@
                         domains = domains.items()
                     for domain, dirname in domains:
-                        t.add(Translations.load(dirname, locale, domain))
+                        self._add(t, Translations.load(dirname, locale,
+                                                       domain))
             self._current.translations = t
             self._activate_failed = False
@@ -184,4 +185,10 @@
             return self._current.translations is not None \
                    or self._activate_failed
+
+        # Internal methods
+
+        def _add(self, t, translations):
+            if isinstance(translations, Translations):
+                t.add(translations)
 
         # Delegated methods
