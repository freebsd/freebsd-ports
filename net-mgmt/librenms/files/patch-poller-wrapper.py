--- poller-wrapper.py.orig	2017-05-28 21:54:20 UTC
+++ poller-wrapper.py
@@ -1,4 +1,4 @@
-#! /usr/bin/env python2
+#! %%LOCALBASE%%/bin/python
 """
  poller-wrapper A small tool which wraps around the poller and tries to
                 guide the polling process with a more modern approach with a
@@ -36,6 +36,8 @@ except:
     print "threading, Queue, sys, subprocess, time, os, json"
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 try:
     import MySQLdb
 except:
