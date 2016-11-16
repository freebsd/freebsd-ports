--- poller-wrapper.py.orig	2014-11-04 16:14:27 UTC
+++ poller-wrapper.py
@@ -38,6 +38,8 @@ except:
     print "threading, Queue, sys, subprocess, time, os, json"
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 try:
     import MySQLdb
 except:
