--- cupshelpers/xmldriverprefs.py.orig	2013-08-29 15:44:39.000000000 +0200
+++ cupshelpers/xmldriverprefs.py	2013-08-29 15:46:18.000000000 +0200
@@ -113,9 +113,9 @@
                     f = drv.rfind ("/")
                     if f != -1:
                         drv = drv[:f]
-                        self._packagehint = "/usr/share/cups/drv/%s" % drv
+                        self._packagehint = "%%PREFIX%%/share/cups/drv/%s" % drv
             else:
-                self._packagehint = "/usr/lib/cups/driver/%s" % scheme
+                self._packagehint = "%%PREFIX%%/libexec/cups/driver/%s" % scheme
 
     def add_attribute (self, name, pattern):
         """
