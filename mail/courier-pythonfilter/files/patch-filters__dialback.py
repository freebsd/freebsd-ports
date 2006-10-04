--- filters/dialback.py.orig   Sun Dec 26 00:01:02 2004
+++ filters/dialback.py        Thu Jul 27 08:33:13 2006
@@ -32,7 +32,7 @@
 # Keep a dictionary of authenticated senders to avoid more work than
 # required.
 _sendersLock = thread.allocate_lock()
-_sendersDir = '/var/state/pythonfilter'
+_sendersDir = '/var/spool/courier/pythonfilter'
 try:
     _goodSenders = anydbm.open(_sendersDir + '/goodsenders', 'c')
     _badSenders = anydbm.open(_sendersDir + '/badsenders', 'c')
