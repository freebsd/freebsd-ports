--- newprinter.py.orig	2019-11-19 17:32:12.439573000 -0400
+++ newprinter.py	2019-11-19 17:37:00.087735000 -0400
@@ -1163,7 +1163,7 @@
                 if (self.device.id and
                     not self.device.type in ("socket", "lpd", "ipp",
                                              "http", "https", "bluetooth")):
-                    name = "%s %s" % (self.device.id_dict["MFG"], 
+                    name = "%s %s" % (self.device.id_dict["MFG"],
                                       self.device.id_dict["MDL"])
             except:
                 nonfatalException ()
@@ -1411,7 +1411,7 @@
         # Does the backend need to be installed?
         if (self.nextnptab_rerun == False and not self.searchedfordriverpackages and
                (self._host == 'localhost' or self._host[0] == '/') and
-               not os.access ("/usr/lib/cups/backend/smb", os.F_OK)):
+               not os.access ("%%PREFIX%%/libexec/cups/backend/smb", os.F_OK)):
             debugprint ("No smb backend so attempting install")
             try:
                 pk = installpackage.PackageKit ()
@@ -2174,7 +2174,7 @@
                 host = device.uri[s:s+e]
         # Try to get make and model via SNMP
         if host:
-            args = ["/usr/lib/cups/backend/snmp", host]
+            args = ["%%PREFIX%%/libexec/cups/backend/snmp", host]
             debugprint (host + ": " + repr(args))
             stdout = None
             try:
@@ -2382,7 +2382,7 @@
                     else:
                         device2.uri = "delete"
         devices = [x for x in devices if x.uri not in ("hp", "hpfax",
-                                                       "hal", "beh", "smb", 
+                                                       "hal", "beh", "smb",
                                                        "scsi", "http", "bjnp",
                                                        "delete")]
         newdevices = []
@@ -4212,7 +4212,7 @@
                 try:
                     # We want this to be in the current natural language,
                     # so we intentionally don't set LC_ALL=C here.
-                    p = subprocess.Popen (['/usr/bin/cupstestppd',
+                    p = subprocess.Popen (['%%PREFIX%%/bin/cupstestppd',
                                            '-rvv', filename],
                                           close_fds=True,
                                           stdin=subprocess.DEVNULL,
