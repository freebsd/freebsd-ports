--- prnt/cups.py.bak	2009-07-31 05:28:04.000000000 -0500
+++ prnt/cups.py	2009-07-31 05:29:26.000000000 -0500
@@ -202,9 +202,9 @@
 
 def getAllowableMIMETypes():
     """
-        Scan all /etc/cups/*.convs files for allowable file formats.
+        Scan all /usr/local/etc/cups/*.convs files for allowable file formats.
     """
-    files = glob.glob("/etc/cups/*.convs")
+    files = glob.glob("/usr/local/etc/cups/*.convs")
 
     allowable_mime_types = []
 
@@ -527,7 +527,7 @@
 
 
 def getErrorLogLevel():
-    cups_conf = '/etc/cups/cupsd.conf'
+    cups_conf = '/usr/local/etc/cups/cupsd.conf'
     try:
         f = file(cups_conf, 'r')
     except OSError:
