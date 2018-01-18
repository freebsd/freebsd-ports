--- poller-wrapper.py.orig	2018-01-14 15:32:19 UTC
+++ poller-wrapper.py
@@ -36,6 +36,8 @@ except:
     print "threading, Queue, sys, subprocess, time, os, json"
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 try:
     import MySQLdb
 except:
