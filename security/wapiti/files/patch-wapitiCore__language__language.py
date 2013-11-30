--- ./wapitiCore/language/language.py.orig	2013-10-02 19:36:32.000000000 +0000
+++ ./wapitiCore/language/language.py	2013-11-28 19:46:44.000000000 +0000
@@ -55,7 +55,8 @@
             # if lang is not specified, default language is used
             defLocale = locale.getdefaultlocale()
             langCounty = defLocale[0]   # en_UK
-            lang = langCounty[:2]  # en
+            if langCounty is not None:
+                lang = langCounty[:2]  # en
         if lang not in self.AVAILABLE_LANGS:
             # if lang is not one of the supported languages, we use english
             print("Oups! No translations found for your language... Using english.")
