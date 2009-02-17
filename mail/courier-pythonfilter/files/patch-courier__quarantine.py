--- courier/quarantine.py.orig	2008-07-14 08:47:05.000000000 +0200
+++ courier/quarantine.py	2008-12-30 13:24:22.000000000 +0100
@@ -30,7 +30,7 @@
 
 # Defaults:
 config = {'siteid': 'local',
-          'dir': '/var/lib/pythonfilter/quarantine',
+          'dir': '/var/spool/courier/pythonfilter/quarantine',
           'days': 14,
           'default': 1}
 
