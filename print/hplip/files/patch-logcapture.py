--- logcapture.py.orig	2022-02-23 07:41:04 UTC
+++ logcapture.py
@@ -37,8 +37,8 @@ from base.sixext import to_string_utf8
 from subprocess import Popen, PIPE
 from installer.core_install import *
 
-CUPS_FILE='/etc/cups/cupsd.conf'
-CUPS_BACKUP_FILE='/etc/cups/cupsd.conf_orginal'
+CUPS_FILE='/usr/local/etc/cups/cupsd.conf'
+CUPS_BACKUP_FILE='/usr/local/etc/cups/cupsd.conf_orginal'
 LOG_FOLDER_PATH='./'
 LOG_FOLDER_NAME='hplip_troubleshoot_logs'
 LOG_FILES=LOG_FOLDER_PATH + LOG_FOLDER_NAME
@@ -332,7 +332,7 @@ for u in USERS:
 sts,out = utils.run('mv -f ./hp-check.log %s'%LOG_FILES)
 if sts != 0:
     log.error("Failed to capture %s log files."%("./hp-check.log"))
-cmd = 'chmod 666  %s/*.log' % LOG_FILES
+cmd = 'chmod 644  %s/*.log' % LOG_FILES
 sts = os_utils.execute(cmd)
 if sts != 0:
     log.error("Failed to change permissions for %s."%(LOG_FILES))
@@ -346,7 +346,7 @@ if sts_compress != 0:
     log.error("Failed to compress %s folder."%(LOG_FILES))
 else:
     log.debug("Changing Permissions of ./%s.tar.gz "%LOG_FOLDER_NAME)
-    sts,out = utils.run('chmod 666 -R ./%s.tar.gz'%(LOG_FOLDER_NAME))
+    sts,out = utils.run('chmod 644 -R ./%s.tar.gz'%(LOG_FOLDER_NAME))
     if sts != 0:
         log.error("Failed to change permissions for %s.tar.gz."%(LOG_FILES))
     log.debug("Removing Temporary log files..")
