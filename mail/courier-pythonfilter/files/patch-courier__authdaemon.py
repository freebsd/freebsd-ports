--- courier/authdaemon.py.orig	2008-12-30 11:49:35.000000000 +0100
+++ courier/authdaemon.py	2008-12-30 11:49:10.000000000 +0100
@@ -23,7 +23,7 @@
 import courier.config
 
 
-socketPath = '/var/spool/authdaemon/socket'
+socketPath = '/var/run/authdaemond/socket'
 _timeoutSock = 10
 _timeoutWrite = 10
 _timeoutRead = 30
