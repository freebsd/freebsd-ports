--- pysmb.py.orig	2008-03-20 11:55:30.000000000 -0400
+++ pysmb.py	2008-03-20 11:56:22.000000000 -0400
@@ -24,13 +24,13 @@
 import sys
 import re
 
-nmblookup = "/usr/bin/nmblookup"
-smbclient = "/usr/bin/smbclient"
+nmblookup = "%%LOCALBASE%%/bin/nmblookup"
+smbclient = "%%LOCALBASE%%/bin/smbclient"
 
 wins = None
 
 def get_wins_server():
-        smbconf = "/etc/samba/smb.conf"
+        smbconf = "%%LOCALBASE%%/etc/smb.conf"
         wsregex = re.compile("\s*wins\s*server.*",re.IGNORECASE)
 	
 	global wins	
