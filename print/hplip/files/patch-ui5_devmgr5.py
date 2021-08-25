--- ui5/devmgr5.py.orig	2022-02-23 07:41:05 UTC
+++ ui5/devmgr5.py
@@ -1073,7 +1073,7 @@ class DevMgr5(Ui_MainWindow_Derived, Ui_MainWindow, QM
                     return
 
                 hplip_conf = configparser.ConfigParser()
-                fp = open("/etc/hp/hplip.conf", "r")
+                fp = open("/usr/local/etc/hp/hplip.conf", "r")
                 hplip_conf.readfp(fp)
                 fp.close()
 
