--- courier/config.py.orig	Fri Dec  1 18:59:03 2006
+++ courier/config.py	Wed Dec 20 23:36:38 2006
@@ -23,32 +23,11 @@
 import socket
 
 
-sysconf = '/etc/courier'
-prefix  = '/usr/lib/courier'
+sysconf = '/usr/local/etc/courier'
+prefix  = '/usr/local'
 spool   = '/var/spool/courier'
 
 
-def _setup():
-    sysconfs = ['/etc/courier', '/usr/lib/courier/etc']
-    prefixes = ['/usr/lib/courier']
-    spools = ['/var/lib/courier', '/var/spool/courier', '/usr/lib/courier/var/spool/courier']
-    global sysconf
-    global prefix
-    global spool
-    for x in sysconfs:
-        if os.path.isdir(x):
-            sysconf = x
-            break
-    for x in prefixes:
-        if os.path.isdir(x):
-            prefix = x
-            break
-    for x in spools:
-        if os.path.isdir(x):
-            spool = x
-            break
-
-
 def read1line(file):
     try:
         cfile = open(sysconf + '/' + file, 'r')
@@ -283,7 +263,3 @@
 
     """
     return getSmtpaccessVal('BLOCK', ip)
-
-
-# Call _setup to correct the module path values
-_setup()
