--- xml2po/xml2po.py.orig	Sun Apr  2 03:47:17 2006
+++ xml2po/xml2po.py	Fri Oct 20 00:57:46 2006
@@ -242,14 +242,10 @@
     text = normalizeString(text, not spacepreserve)
     if (text.strip() == ''):
         return text
-    file = open(mofile, "rb")
-    if file:
-        myfallback = NoneTranslations()
-        gt = gettext.GNUTranslations(file)
-        gt.add_fallback(myfallback)
-        if gt:
-            res = gt.ugettext(text.decode('utf-8'))
-            return res
+    global gt
+    if gt:
+        res = gt.ugettext(text.decode('utf-8'))
+        return res
 
     return text
 
@@ -648,6 +644,7 @@
 filename = ''
 origxml = ''
 mofile = ''
+gt = None
 ultimate = [ ]
 ignored = [ ]
 filenames = [ ]
@@ -763,6 +760,11 @@
 if mode=='merge' and mofile=='':
     print >> sys.stderr, "Error: You must specify MO file when merging translations."
     sys.exit(3)
+
+file = open(mofile, "rb")
+if file:
+    gt = gettext.GNUTranslations(file)
+    gt.add_fallback(NoneTranslations())
 
 ultimate_tags = read_finaltags(ultimate)
 ignored_tags = read_ignoredtags(ignored)
