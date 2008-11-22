--- system-config-printer.py.orig	2008-11-21 11:19:25.000000000 -0600
+++ system-config-printer.py	2008-11-22 11:30:37.732537129 -0600
@@ -3668,7 +3668,7 @@
         # Try to get make and model via SNMP
         if host:
             os.environ["HOST"] = host
-            cmd = '/usr/lib/cups/backend/snmp "${HOST}"'
+            cmd = '%%LOCALBASE%%/lib/cups/backend/snmp "${HOST}"'
             debugprint (host + ": " + cmd)
             stdout = None
             try:
@@ -5140,7 +5140,7 @@
                 try:
                     # We want this to be in the current natural language,
                     # so we intentionally don't set LC_ALL=C here.
-                    p = subprocess.Popen (['/usr/bin/cupstestppd',
+                    p = subprocess.Popen (['%%LOCALBASE%%/bin/cupstestppd',
                                            '-rvv', filename],
                                           stdin=file("/dev/null"),
                                           stdout=subprocess.PIPE,
@@ -5433,7 +5433,7 @@
         (pkgs, exes) = cupshelpers.missingPackagesAndExecutables (ppd)
         if len (pkgs) > 0 or len (exes) > 0:
             # We didn't find a necessary executable.  Complain.
-            install = "/usr/bin/gpk-install-package-name"
+            install = "/usr/bin/true"
             if len (pkgs) > 0 and os.access (install, os.X_OK):
                 pkg = pkgs[0]
                 install_text = ('<span weight="bold" size="larger">' +
