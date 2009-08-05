--- check.py.bak	2009-07-31 05:33:11.000000000 -0500
+++ check.py	2009-07-31 05:34:36.000000000 -0500
@@ -337,7 +337,7 @@
             num_errors += 1
 
     if cups_ok:
-        cups_conf = '/etc/cups/cupsd.conf'
+        cups_conf = '/usr/local/etc/cups/cupsd.conf'
 
         try:
             f = file(cups_conf, 'r')
@@ -600,7 +600,7 @@
                 #log.info("Installed in HPLIP?: %s" % x)
                 log.info("Device URI: %s" % device_uri)
 
-                ppd = os.path.join('/etc/cups/ppd', printer_name + '.ppd')
+                ppd = os.path.join('/usr/local/etc/cups/ppd', printer_name + '.ppd')
 
                 if os.path.exists(ppd):
                     log.info("PPD: %s" % ppd)
