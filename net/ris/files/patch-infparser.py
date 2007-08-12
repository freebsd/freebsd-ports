--- infparser.py.orig	Tue Aug  7 16:10:14 2007
+++ infparser.py	Tue Aug  7 17:09:32 2007
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#! @PYTHON_CMD@
 # -*- Mode: Python; tab-width: 4 -*-
 #
 # Inf Driver parser
@@ -293,28 +293,6 @@
         if inffile.split('/').pop() not in exclude:
             devlist.update(scan_inf(inffile))
 
-    print 'Compiled %d drivers' % len(devlist)
-
-    fd = open('devlist.cache', 'w')
+    fd = open('@DEVLIST_CACHE@', 'w')
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
