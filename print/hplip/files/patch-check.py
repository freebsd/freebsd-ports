--- check.py.orig	2022-02-23 07:41:04 UTC
+++ check.py
@@ -139,9 +139,9 @@ def get_comment(package, Inst_status, installed_ver):
                 comment = "Python Programming is not supported if version is lessthan 2.2" 
     elif package == 'hpaio':
         if Inst_status == 'OK':
-            comment = "'hpaio found in /etc/sane.d/dll.conf'"
+            comment = "'hpaio found in /usr/local/etc/sane.d/dll.d/hpaio'"
         else:
-            comment = "'hpaio not found in /etc/sane.d/dll.conf. hpaio needs to be added in this file.'"
+            comment = "'hpaio not found in /usr/local/etc/sane.d/dll.d/hpaio. hpaio needs to be added in this file.'"
     elif package == 'cupsext' or package == 'pcardext' or package == 'hpmudext':
         if Inst_status != 'OK':
             comment = "'Not Found or Failed to load, Please reinstall HPLIP'"
@@ -326,9 +326,9 @@ class DependenciesCheck(object):
                 log.warn("HPLIP-Installation: Auto installation is not supported for %s distro  %s version " %(self.core.distro, self.core.distro_version))
 
             log.info()
-            log.info(log.bold("Current contents of '/etc/hp/hplip.conf' file:"))
+            log.info(log.bold("Current contents of '/usr/local/etc/hp/hplip.conf' file:"))
             try:
-                output = open('/etc/hp/hplip.conf', 'r').read()
+                output = open('/usr/local/etc/hp/hplip.conf', 'r').read()
             except (IOError, OSError) as e:
                 log.error("Could not access file: %s. Check HPLIP installation." % e.strerror)
                 self.num_errors += 1
@@ -502,7 +502,7 @@ class DependenciesCheck(object):
                         #log.info("Installed in HPLIP?: %s" % x)
                         log.info("Device URI: %s" % device_uri)
 
-                        ppd = os.path.join('/etc/cups/ppd', printer_name + '.ppd')
+                        ppd = os.path.join('/usr/local/etc/cups/ppd', printer_name + '.ppd')
 
                         if os.path.exists(ppd):
                             log.info("PPD: %s" % ppd)
