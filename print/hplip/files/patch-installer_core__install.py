--- installer/core_install.py.orig	2022-02-23 07:41:04 UTC
+++ installer/core_install.py
@@ -1358,7 +1358,7 @@ class CoreInstall(object):
 
                 if not found:
                     st = os.stat('/etc/sane.d/dll.conf')
-                    cmd = self.passwordObj.getAuthCmd() % 'chmod 777 /etc/sane.d/dll.conf'
+                    cmd = self.passwordObj.getAuthCmd() % 'chmod 644 /etc/sane.d/dll.conf'
                     log.debug("cmd=%s" % cmd)
                     utils.run(cmd, self.passwordObj)
                     try:
