--- newprinter.py.orig	2015-01-13 11:56:34.450684352 +0100
+++ newprinter.py	2015-01-13 11:57:28.467679877 +0100
@@ -1067,7 +1067,7 @@
 
                             (self._host == 'localhost' or
                              self._host[0] == '/') and
-                            not os.access ("/usr/lib/cups/backend/smb", os.F_OK)):
+                            not os.access ("%%PREFIX%%/libexec/cups/backend/smb", os.F_OK)):
                             debugprint ("No smb backend so attempting install")
                             try:
                                 pk = installpackage.PackageKit ()
@@ -1909,7 +1909,7 @@
                 host = device.uri[s:s+e]
         # Try to get make and model via SNMP
         if host:
-            args = ["/usr/lib/cups/backend/snmp", host]
+            args = ["%%PREFIX%%/libexec/cups/backend/snmp", host]
             debugprint (host + ": " + repr(args))
             stdout = None
             try:
@@ -3842,7 +3842,7 @@
                 try:
                     # We want this to be in the current natural language,
                     # so we intentionally don't set LC_ALL=C here.
-                    p = subprocess.Popen (['/usr/bin/cupstestppd',
+                    p = subprocess.Popen (['%%PREFIX%%/bin/cupstestppd',
                                            '-rvv', filename],
                                           close_fds=True,
                                           stdin=file("/dev/null"),
