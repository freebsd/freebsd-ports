--- Stylesheet.py.orig	Thu Aug 30 10:35:51 2001
+++ Stylesheet.py	Thu Aug 30 10:36:05 2001
@@ -42,7 +42,7 @@
         fonts = self.prefs.GetGroup('styles-fonts')
         massaged = []
         for ((g, c), v) in fonts:
-            massaged.append((g, c), v % fparms_dict)
+            massaged.append(((g, c), v % fparms_dict))
         self.dictify_group(massaged)
 
     def __getattr__(self, composite):
