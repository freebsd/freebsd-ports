--- poller-wrapper.py.orig	2018-08-29 23:25:16 UTC
+++ poller-wrapper.py
@@ -37,6 +37,8 @@ except:
     print "threading, Queue, sys, subprocess, time, os, json"
     sys.exit(2)
 
+os.environ['PATH'] += ':/usr/local/sbin:/usr/local/bin'
+
 try:
     import MySQLdb
 except:
