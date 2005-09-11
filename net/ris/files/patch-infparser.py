--- infparser.py.orig	Fri Sep  2 14:15:32 2005
+++ infparser.py	Fri Sep  2 14:18:12 2005
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#! @PYTHON_CMD@
 # -*- Mode: Python; tab-width: 4 -*-
 #
 # Inf Driver parser
@@ -143,7 +143,7 @@
     if name.endswith('.services'):
         prefix = name.split('.services', 1)[0]
         check = prefix.split('.')
-        if check[-1].startswith('nt'):
+        if check[-1].startswith('nt') and not check[-1].endswith('64'):
             check = check[:-1]
         check = check + ['services']
         name = '.'.join(check)
@@ -154,7 +154,7 @@
     while check[-1].isdigit() and len(check)>1:
         check = check[:-1]
     
-    if check[-1].startswith('nt'):
+    if check[-1].startswith('nt') and not check[-1].endswith('64'):
         check = check[:-1]
 
     name = '.'.join(check)
@@ -283,8 +283,8 @@
         if inffile.split('/').pop() not in exclude:
             devlist.update(scan_inf(inffile))
     
-    print 'Compiled %d drivers' % len(devlist)
+    print 'Starting inf parser: compiled %d drivers.' % len(devlist)
 
-    fd = open('devlist.cache','w')
+    fd = open('@DEVLIST_CACHE@','w')
     dump(devlist, fd)
     fd.close()
