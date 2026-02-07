--- troubleshoot/CheckUSBPermissions.py.orig	2008-07-26 13:36:20.440361271 -0500
+++ troubleshoot/CheckUSBPermissions.py	2008-07-26 13:36:36.255172372 -0500
@@ -51,7 +51,7 @@
         if not os.access (LSUSB, os.X_OK):
             return False
 
-        GETFACL = "/usr/bin/getfacl"
+        GETFACL = "/bin/getfacl"
         if not os.access (GETFACL, os.X_OK):
             return False
 
