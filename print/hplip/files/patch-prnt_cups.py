--- prnt/cups.py.orig	2025-11-18 10:05:47 UTC
+++ prnt/cups.py
@@ -226,7 +226,7 @@ def isfamilydrv(ppds):
      #   for m in models.FAMILY_CLASSES:
       #       if m in f:
        #          family_check=1
-    filename_config = "/etc/hp/hplip.conf"
+    filename_config = "/usr/local/etc/hp/hplip.conf"
     file_conf = open(filename_config,'r')
     for line in file_conf:
         if 'class-driver' in line:
@@ -238,8 +238,8 @@ def getPPDPath(addtional_paths=None):
                 
 def getPPDPath(addtional_paths=None):
     """
-        Returns the CUPS ppd path (not the foomatic one under /usr/share/ppd).
-        Usually this is /usr/share/cups/model.
+        Returns the CUPS ppd path (not the foomatic one under /usr/local/share/ppd).
+        Usually this is /usr/local/share/cups/model.
     """
     if addtional_paths is None:
         addtional_paths = []
@@ -257,7 +257,7 @@ def getPPDPath1(addtional_paths=None):
         return path for hplip ppds. 
     """
    
-    filename_config = "/etc/hp/hplip.conf"
+    filename_config = "/usr/local/etc/hp/hplip.conf"
     file_conf = open(filename_config,'r')
     for line in file_conf:
         if 'ppd=' in line:
@@ -271,16 +271,16 @@ def getAllowableMIMETypes():
 
 def getAllowableMIMETypes():
     """
-        Scan all /etc/cups/*.convs and /usr/share/cups/mime
+        Scan all /usr/local/etc/cups/*.convs and /usr/local/share/cups/mime
         files for allowable file formats.
     """
     paths = []
     allowable_mime_types = []
     files = []
-    if os.path.exists("/etc/cups"):
-        paths.append("/etc/cups/*.convs")
-    if os.path.exists("/usr/share/cups/mime"):
-        paths.append("/usr/share/cups/mime/*.convs")
+    if os.path.exists("/usr/local/etc/cups"):
+        paths.append("/usr/local/etc/cups/*.convs")
+    if os.path.exists("/usr/local/share/cups/mime"):
+        paths.append("/usr/local/share/cups/mime/*.convs")
     for path in paths:
         files.extend(glob.glob(path))
     for f in files:
@@ -337,11 +337,11 @@ def getSystemPPDs():
     else:  # CUPS 1.2.x or later
         log.debug("(CUPS 1.2.x) Getting list of PPDs using CUPS_GET_PPDS...")
         ppd_dict = cupsext.getPPDList()
-        cups_ppd_path = getPPDPath()  # usually /usr/share/cups/model
-        foomatic_ppd_path = sys_conf.get('dirs', 'ppdbase', '/usr/share/ppd')
+        cups_ppd_path = getPPDPath()  # usually /usr/local/share/cups/model
+        foomatic_ppd_path = sys_conf.get('dirs', 'ppdbase', '/usr/local/share/ppd')
  
         if not foomatic_ppd_path or not os.path.exists(foomatic_ppd_path):
-            foomatic_ppd_path = '/usr/share/ppd'
+            foomatic_ppd_path = '/usr/local/share/ppd'
  
         log.debug("CUPS PPD base path = %s" % cups_ppd_path)
         log.debug("Foomatic PPD base path = %s" % foomatic_ppd_path)
@@ -378,7 +378,7 @@ def getSystemPPDs():
                                     path = ppd
  
                 # Separate drv and model ppds
-                if path.startswith("/usr/share/cups/model/hp/"):
+                if path.startswith("/usr/local/share/cups/model/hp/"):
                     model_ppds.append((path, desc))
                 elif path.startswith("drv:///"):
                     drv_ppds.append((path, desc))
@@ -709,7 +709,7 @@ def getErrorLogLevel():
 
 
 def getErrorLogLevel():
-    cups_conf = '/etc/cups/cupsd.conf'
+    cups_conf = '/usr/local/etc/cups/cupsd.conf'
     try:
         f = open(cups_conf, 'r')
     except OSError:
