--- lottanzb/core.py.orig	2009-09-21 14:25:17.000000000 -0600
+++ lottanzb/core.py	2009-09-21 14:26:31.000000000 -0600
@@ -135,9 +135,12 @@
         domain = "lottanzb"
         
         for module in (gettext, locale):
-            module.bindtextdomain(domain, resources.get_locale())
-            module.bind_textdomain_codeset(domain, "UTF-8")
-            module.textdomain(domain)
+            try:
+                 module.bindtextdomain(domain, resources.get_locale())
+                 module.bind_textdomain_codeset(domain, "UTF-8")
+                 module.textdomain(domain)
+            except AttributeError:
+                 pass
     
     @staticmethod
     def setup_logging():
