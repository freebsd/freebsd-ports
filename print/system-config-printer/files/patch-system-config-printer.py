--- system-config-printer.py.orig	2008-03-20 11:58:46.000000000 -0400
+++ system-config-printer.py	2008-03-20 12:01:44.000000000 -0400
@@ -72,7 +72,7 @@
 import gettext
 gettext.textdomain (domain)
 gtk.glade.bindtextdomain (domain)
-pkgdata = '/usr/share/' + domain
+pkgdata = '%%PREFIX%%/share/' + domain
 glade_file = pkgdata + '/' + domain + '.glade'
 sys.path.append (pkgdata)
 
@@ -2987,7 +2987,7 @@
         # Try to get make and model via SNMP
         if host:
             os.environ["HOST"] = host
-            cmd = '/usr/lib/cups/backend/snmp "${HOST}" 2>/dev/null'
+            cmd = '%%LOCALBASE%%/libexec/cups/backend/snmp "${HOST}" 2>/dev/null'
             debugprint (host + ": " + cmd)
             p = os.popen(cmd, 'r')
             output = p.read()
@@ -4055,7 +4055,7 @@
                 os.environ["PPD"] = filename
                 # We want this to be in the current natural language,
                 # so we intentionally don't set LC_ALL=C here.
-                p = os.popen ('/usr/bin/cupstestppd -rvv "$PPD"', 'r')
+                p = os.popen ('%%LOCALBASE%%/bin/cupstestppd -rvv "$PPD"', 'r')
                 output = p.readlines ()
                 p.close ()
                 err += reduce (lambda x, y: x + y, output)
@@ -4345,7 +4345,7 @@
         (pkgs, exes) = cupshelpers.missingPackagesAndExecutables (ppd)
         if len (pkgs) > 0 or len (exes) > 0:
             # We didn't find a necessary executable.  Complain.
-            install = "/usr/bin/system-install-packages"
+            install = "/usr/bin/true"
             if len (pkgs) > 0 and os.access (install, os.X_OK):
                 pkg = pkgs[0]
                 install_text = ('<span weight="bold" size="larger">' +
