--- ./system-config-printer-kde/system-config-printer-kde.py.orig	2008-12-21 23:20:45.000000000 +0300
+++ ./system-config-printer-kde/system-config-printer-kde.py	2009-05-04 22:50:28.000000000 +0400
@@ -33,7 +33,7 @@
 import thread
 
 #load modules from system-config-printer-common (debug, smburi), change path here if you have it installed elsewhere
-SYSTEM_CONFIG_PRINTER_DIR = "/usr/share/system-config-printer"
+SYSTEM_CONFIG_PRINTER_DIR = "%%LOCALBASE%%/share/system-config-printer"
 if os.path.exists(SYSTEM_CONFIG_PRINTER_DIR + "/debug.py"):
     sys.path.append(SYSTEM_CONFIG_PRINTER_DIR)
 
@@ -2265,7 +2265,7 @@
         # Try to get make and model via SNMP
         if host:
             os.environ["HOST"] = host
-            cmd = '/usr/lib/cups/backend/snmp "${HOST}"'
+            cmd = '%%LOCALBASE%%/libexec/cups/backend/snmp "${HOST}"'
             debugprint (host + ": " + cmd)
             stdout = None
             try:
@@ -2920,7 +2920,7 @@
                 os.environ["PPD"] = filename
                 # We want this to be in the current natural language,
                 # so we intentionally don't set LC_ALL=C here.
-                p = os.popen ('/usr/bin/cupstestppd -rvv "$PPD"', 'r')
+                p = os.popen ('%%LOCALBASE%%/bin/cupstestppd -rvv "$PPD"', 'r')
                 output = p.readlines ()
                 p.close ()
                 err += reduce (lambda x, y: x + y, output)
@@ -3168,7 +3168,7 @@
         (pkgs, exes) = cupshelpers.missingPackagesAndExecutables (ppd)
         if len (pkgs) > 0 or len (exes) > 0:
             # We didn't find a necessary executable.  Complain.
-            install = "/usr/bin/system-install-packages"
+            install = "/usr/bin/true"
             if len (pkgs) > 0 and os.access (install, os.X_OK):
                 pkg = pkgs[0]
                 install_text = ('<span weight="bold" size="larger">' +
