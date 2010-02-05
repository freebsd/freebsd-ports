--- infparser.py.orig	2010-01-07 20:00:17.171071673 +0300
+++ infparser.py	2010-01-07 20:02:24.200743110 +0300
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#! @PYTHON_CMD@
 # -*- Mode: Python; tab-width: 4 -*-
 #
 # Inf Driver parser
@@ -312,28 +312,6 @@
                 print format_exc()
                 print '---- CUT HERE ----'
 
-    print 'Compiled %d drivers' % len(devlist)
-
-    fd = open('devlist.cache', 'wb')
+    fd = open('@DEVLIST_CACHE@', 'wb')
     dump(devlist, fd)
     fd.close()
-    print 'generated devlist.cache'
-
-    fd = open('nics.txt', 'w')
-    drvhash = {}
-    for nic in devlist.items():
-        entry = nic[0].split('&')
-        if len(entry) < 2: continue # just to be sure
-        if not entry[0].startswith('PCI'): continue # skip usb
-        vid = entry[0].split('VEN_').pop().lower()
-        pid = entry[1].split('DEV_').pop().lower()
-        key = (vid, pid)
-        line = '%4s %4s %s %s\n' % (vid, pid, nic[1]['drv'], nic[1]['svc'])
-        drvhash[key] = line
-
-    drvlist = drvhash.values()
-    drvlist.sort()
-    fd.writelines(drvlist)
-    fd.close()
-
-    print 'generated nics.txt'
