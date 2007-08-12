--- binlsrv.py.orig	Tue Aug  7 16:06:15 2007
+++ binlsrv.py	Tue Aug  7 16:35:02 2007
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#! @PYTHON_CMD@
 # -*- Mode: Python; tab-width: 4 -*-
 #
 # Boot Information Negotiation Layer - OpenSource Implementation
@@ -40,7 +40,7 @@
                     [--pid pidfile] [devlist.cache]
 -h, --help     : show this help
 -d, --daemon   : daemonize, unix only [false]
--l, --logfile= : logfile when used in daemon mode [/var/log/binlsrv.log]
+-l, --logfile= : logfile when used in daemon mode [@LOG_FILE@]
 -a, --address= : ip address to bind to [all interfaces]
 -p, --port=    : port to bind to [4011]
     --pid=     : pid file to use instead of the default
@@ -839,11 +839,11 @@
     ## Defaults
     global pidfile, s
     daemon  = False
-    logfile = '/var/log/binlsrv.log'
+    logfile = '@LOG_FILE@'
     address = ''
     port    = 4011
-    devfile = 'devlist.cache'
-    pidfile = '/var/run/binlsrv.pid'
+    devfile = '@DEVLIST_CACHE@'
+    pidfile = '@PID_FILE@'
 
     ## Parse command line arguments
     shortopts = 'hdl:a:p:'
