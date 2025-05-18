--- configure.py.orig	2024-10-16 14:36:50 UTC
+++ configure.py
@@ -1876,7 +1876,7 @@ def configure_intl(o):
   elif with_intl == 'system-icu':
     # ICU from pkg-config.
     o['variables']['v8_enable_i18n_support'] = 1
-    pkgicu = pkg_config('icu-i18n')
+    pkgicu = pkg_config(['icu-i18n', 'icu-uc'])
     if not pkgicu[0]:
       error('''Could not load pkg-config data for "icu-i18n".
        See above errors or the README.md.''')
