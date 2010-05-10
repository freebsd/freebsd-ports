--- system-config-printer.py.orig	2009-12-22 09:44:19.000000000 -0500
+++ system-config-printer.py	2009-12-29 00:35:54.000000000 -0500
@@ -4344,7 +4344,7 @@
                 if may_be_ps:
                     debugprint ("Printer might support PostScript")
                     try:
-                        os.stat ("/usr/share/cups/model/foomatic-db-ppds")
+                        os.stat ("%%LOCALBASE%%/share/cups/model/foomatic-db-ppds")
                         debugprint ("foomatic-db-ppds already installed")
                     except OSError:
                         debugprint ("foomatic-db-ppds not yet installed")
@@ -4892,11 +4892,11 @@
                 # Problem executing command.
                 return True # assume plugin not required
         else:
-            if glob.glob("/usr/share/hplip/data/plugin/*%s*plugin*" %
+            if glob.glob("%%LOCALBASE%%share/hplip/data/plugin/*%s*plugin*" %
                          hplip_version):
                 if hplip_version.startswith("2"):
                     try:
-                        f = open('/etc/hp/hplip.conf', 'r')
+                        f = open('%%LOCALBASE%%/etc/hp/hplip.conf', 'r')
                         for line in f:
                             if line.strip ().startswith("plugin") and \
                                     line.strip ().endswith("1"):
@@ -5082,7 +5082,7 @@
         # Try to get make and model via SNMP
         if host:
             os.environ["HOST"] = host
-            cmd = '/usr/lib/cups/backend/snmp "${HOST}"'
+            cmd = '%%LOCALBASE%%/libexec/cups/backend/snmp "${HOST}"'
             debugprint (host + ": " + cmd)
             stdout = None
             try:
@@ -6621,7 +6621,7 @@
                 try:
                     # We want this to be in the current natural language,
                     # so we intentionally don't set LC_ALL=C here.
-                    p = subprocess.Popen (['/usr/bin/cupstestppd',
+                    p = subprocess.Popen (['%%LOCALBASE%%/bin/cupstestppd',
                                            '-rvv', filename],
                                           stdin=file("/dev/null"),
                                           stdout=subprocess.PIPE,
