--- base/queues.py.orig	2022-02-23 07:41:04 UTC
+++ base/queues.py
@@ -128,7 +128,7 @@ def parseQueues(mode):
                     is_hp = True
 
             log.debug("Device URI: %s" % device_uri)
-            ppd_file = os.path.join('/etc/cups/ppd', printer_name + '.ppd')
+            ppd_file = os.path.join('/usr/local/etc/cups/ppd', printer_name + '.ppd')
             ppd_fileType = None
             PPDFileError = False
             if not os.path.exists(ppd_file):
