--- BitTorrent/__init__.py.orig	Sun Nov 20 23:18:59 2005
+++ BitTorrent/__init__.py	Sun Nov 20 23:19:07 2005
@@ -64,7 +64,7 @@
     'te'   :u'	తెలుగు'              ,
     }
 
-#language_names.update(unfinished_language_names)
+language_names.update(unfinished_language_names)
 
 languages = language_names.keys()
 languages.sort()
