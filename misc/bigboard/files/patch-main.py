--- main.py	2008-04-29 02:40:59.000000000 +0530
+++ main.py.new	2008-05-28 12:51:14.000000000 +0530
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!/usr/bin/env python
 
 import os, sys, threading, getopt, logging, StringIO, stat, signal
 import xml.dom.minidom, urllib2, urlparse, subprocess, weakref
@@ -48,7 +48,7 @@
 
 GCONF_PREFIX = '/apps/bigboard/'
 
-REEXEC_CMD = os.getenv('BB_REEXEC') or '/usr/bin/bigboard'
+REEXEC_CMD = os.getenv('BB_REEXEC') or '%%LOCALBASE%%/bin/bigboard'
 REEXEC_CMD = os.path.abspath(REEXEC_CMD)
 
 BB_DATADIR = os.getenv('BB_DATADIR')
@@ -69,7 +69,7 @@
     if datadir_env:
         datadirs = datadir_env.split(':')
     else:
-        datadirs = ['/usr/share/']
+        datadirs = ['%%LOCALBASE%%/share/']
     return map(lambda x: os.path.join(x, 'bigboard'), datadirs)
 
 def _find_in_datadir(fname):
