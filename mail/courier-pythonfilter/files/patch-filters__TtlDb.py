--- filters/TtlDb.py.orig	Tue Dec 19 21:12:26 2006
+++ filters/TtlDb.py	Wed Dec 20 22:30:21 2006
@@ -22,7 +22,7 @@
 import time
 
 
-_dbmDir = '/var/state/pythonfilter'
+_dbmDir = '/var/spool/courier/pythonfilter'
 
 
 class TtlDbError(Exception):
