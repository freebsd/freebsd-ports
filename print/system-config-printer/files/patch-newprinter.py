--- newprinter.py.orig	2013-08-29 15:46:51.000000000 +0200
+++ newprinter.py	2013-08-29 15:48:44.000000000 +0200
@@ -1038,7 +1038,7 @@
                     # Does the backend need to be installed?
                     if ((self._host == 'localhost' or
                          self._host[0] == '/') and
-                        not os.access ("/usr/lib/cups/backend/smb", os.F_OK)):
+                        not os.access ("%%PREFIX%%/libexec/cups/backend/smb", os.F_OK)):
                         p = subprocess.Popen (["gpk-install-package-name",
                                                "samba-client"],
                                               close_fds=True,
@@ -1844,7 +1844,7 @@
                 host = device.uri[s:s+e]
         # Try to get make and model via SNMP
         if host:
-            args = ["/usr/lib/cups/backend/snmp", host]
+            args = ["%%PREFIX%%/libexec/cups/backend/snmp", host]
             debugprint (host + ": " + repr(args))
             stdout = None
             try:
@@ -3799,7 +3799,7 @@
                 try:
                     # We want this to be in the current natural language,
                     # so we intentionally don't set LC_ALL=C here.
-                    p = subprocess.Popen (['/usr/bin/cupstestppd',
+                    p = subprocess.Popen (['%%PREFIX%%/bin/cupstestppd',
                                            '-rvv', filename],
                                           close_fds=True,
                                           stdin=file("/dev/null"),
