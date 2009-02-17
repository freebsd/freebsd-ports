--- filters/clamav.py.orig	2008-03-23 09:06:04.000000000 +0100
+++ filters/clamav.py	2008-12-30 14:45:03.000000000 +0100
@@ -22,7 +22,7 @@
 import courier.config
 import courier.quarantine
 
-localSocket = ''
+localSocket = '/var/run/clamav/clamd.sock'
 action = 'reject'
 
 try:
