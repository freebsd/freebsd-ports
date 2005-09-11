--- binlsrv.py.orig	Fri Sep  2 14:15:31 2005
+++ binlsrv.py	Fri Sep  2 14:21:11 2005
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#! @PYTHON_CMD@
 # -*- Mode: Python; tab-width: 4 -*-
 #
 # Boot Information Negotiation Layer - OpenSource Implementation
@@ -671,7 +671,12 @@
 
         import sys
 
-        if (fork()): sys_exit()
+        pid=fork()
+        if (pid):
+           pidfile=open('@PID_FILE@', 'w')
+           pidfile.write('%d\n' % pid)
+           pidfile.close()
+           sys_exit()
         
         close(sys.stdin.fileno())
         sys.stdin  = open('/dev/null')
@@ -683,7 +688,7 @@
         sys.stderr = Log(open(LOGFILE, 'a+'))
 
     try:
-        devlist = load(open('devlist.cache'))
+        devlist = load(open('@DEVLIST_CACHE@'))
     except:
         print 'Could not load devlist.cache, build it with infparser.py'
         sys_exit(-1)
@@ -694,7 +699,6 @@
     s = socket(AF_INET, SOCK_DGRAM)
     s.bind(('', 4011))
     
-    print 'Binlserver started... pid %d' % getpid()
     while 1:
         addr, t, data = get_packet(s)
         if t == FILEREQ:
