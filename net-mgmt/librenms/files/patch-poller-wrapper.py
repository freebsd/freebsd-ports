--- poller-wrapper.py.orig	2014-11-04 16:14:27 UTC
+++ poller-wrapper.py
@@ -1,4 +1,4 @@
-#! /usr/bin/env python
+#! %%LOCALBASE%%/bin/python
 """
  poller-wrapper A small tool which wraps around the Observium poller
                 and tries to guide the polling process with a more modern
@@ -38,6 +38,8 @@ except:
     print "threading, Queue, sys, subprocess, time, os, json"
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 try:
     import MySQLdb
 except:
