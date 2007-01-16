--- filters/greylist.py.orig	Mon Dec 11 23:58:12 2006
+++ filters/greylist.py	Mon Jan  1 21:00:42 2007
@@ -51,7 +51,7 @@
     sys.stderr.write(e.message)
     sys.exit(1)
 
-_whitelistDir = '/var/state/pythonfilter'
+_whitelistDir = '/var/spool/courier/pythonfilter'
 try:
     # messages which include these mail addresses either as sender or recipient
     # should not be greylisted (could be your customer database)
