--- src/classes/language.py.orig	2023-04-20 05:27:15 UTC
+++ src/classes/language.py
@@ -101,7 +101,10 @@ def init_language():
         log.info("Language overridden on command line, using: {}".format(info.CMDLINE_LANGUAGE))
 
     # Default the locale to C, for number formatting
-    locale.setlocale(locale.LC_ALL, 'C')
+    if ".UTF-8" in locale.setlocale(locale.LC_ALL):
+        locale.setlocale(locale.LC_ALL, 'C.UTF-8')
+    else:
+        locale.setlocale(locale.LC_ALL, 'C')
 
     # Loop through environment variables
     found_language = False
