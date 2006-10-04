--- filters/comeagain.py.orig  Mon Dec 13 09:26:13 2004
+++ filters/comeagain.py       Thu Jul 27 08:34:25 2006
@@ -27,7 +27,7 @@

 # Keep a dictionary of sender/recipient pairs that we've seen before
 _sendersLock = thread.allocate_lock()
-_sendersDir = '/var/state/pythonfilter'
+_sendersDir = '/var/spool/courier/pythonfilter'
 try:
     _senders = anydbm.open(_sendersDir + '/correspondents', 'c')
 except:
