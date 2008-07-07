--- SABnzbd.py	2008-07-04 12:31:58.000000000 -0700
+++ SABnzbd.py.bak	2008-07-06 12:33:06.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/python -OO
+#!/usr/local/bin/python2.5 -OO
 # Copyright 2008 The SABnzbd-Team <team@sabnzbd.org>
 #
 # This program is free software; you can redistribute it and/or
@@ -164,7 +164,7 @@
         print "fork() failed"
         sys.exit(1)
 
-    os.chdir(sabnzbd.DIR_PROG)
+    os.chdir(%%PREFIX%%)
     os.setsid()
     # Make sure I can read my own files and shut out others
     prev= os.umask(0)
@@ -301,7 +301,7 @@
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sys.argv[0]))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
     sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
+    sabnzbd.DIR_INTERFACES = real_path(%%PREFIX%%, DEF_INTERFACES)
 
     # Need console logging for SABnzbd.py and SABnzbd-console.exe
     consoleLogging = (not hasattr(sys, "frozen")) or (sabnzbd.MY_NAME.lower().find('-console') > 0)
@@ -684,7 +684,7 @@
 
     log_dir = dir_setup(cfg, 'log_dir', sabnzbd.DIR_LCLDATA, DEF_LOG_DIR)
 
-    os.chdir(sabnzbd.DIR_PROG)
+    os.chdir(%%PREFIX%%)
 
     web_dir  = Web_Template('web_dir',  DEF_STDINTF,  web_dir)
     web_dir2 = Web_Template('web_dir2', '', web_dir2)
