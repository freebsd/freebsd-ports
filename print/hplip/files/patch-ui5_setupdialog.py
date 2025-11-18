--- ui5/setupdialog.py.orig	2025-11-18 10:32:03 UTC
+++ ui5/setupdialog.py
@@ -790,7 +790,7 @@ class SetupDialog(QDialog, Ui_Dialog):
             sys_ppd_path = config.get("dirs", "ppd")
         except Exception as e:
             log.error("Error reading config file: %s" % e)
-            sys_ppd_path = "/usr/share/ppd/HP"
+            sys_ppd_path = "/usr/local/share/ppd/HP"
         
         try:
             ppdName = cups.getPpdName(self.model).strip()
@@ -1039,7 +1039,7 @@ class SetupDialog(QDialog, Ui_Dialog):
         this is for driverless usb printer held by ippusbxd service on ubuntu 20 and above.
         For network devices follow the old code.
         '''
-        if(self.bus == "usb" and not os.path.isdir('/usr/share/ipp-usb/quirks')):
+        if(self.bus == "usb" and not os.path.isdir('/usr/local/share/ipp-usb/quirks')):
             from base import local
             from base.local import detectLocalDevices
             try:
