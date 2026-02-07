--- probe_printer.py.orig	2013-08-29 15:54:06.000000000 +0200
+++ probe_printer.py	2013-08-29 15:54:27.000000000 +0200
@@ -275,7 +275,7 @@
         null = file ("/dev/null", "r+")
         try:
             debugprint ("snmp: trying")
-            p = subprocess.Popen (args=["/usr/lib/cups/backend/snmp",
+            p = subprocess.Popen (args=["%%PREFIX%%/libexec/cups/backend/snmp",
                                         self.hostname],
                                   close_fds=True,
                                   stdin=null,
