--- BitTorrent/Rerequester.py	Sat Apr  3 01:10:23 2004
+++ BitTorrent/Rerequester.py	Sun Apr 18 17:03:33 2004
@@ -5,7 +5,7 @@
 from btformats import check_peers
 from bencode import bdecode
 from threading import Thread, Lock
-from socket import error
+from socket import error, gethostbyname
 from time import time
 from random import randrange
 from binascii import b2a_hex
@@ -45,8 +45,7 @@
         self.url = ('%s?info_hash=%s&peer_id=%s&port=%s&key=%s' %
             (url, quote(infohash), quote(myid), str(port),
             b2a_hex(''.join([chr(randrange(256)) for i in xrange(4)]))))
-        if ip != '':
-            self.url += '&ip=' + quote(ip)
+        self.ip = ip
         self.interval = interval
         self.last = None
         self.trackerid = None
@@ -108,6 +107,8 @@
 
     def rerequest(self, url, set):
         try:
+            if self.ip:
+                url += '&ip=' + gethostbyname(self.ip)
             print "opening url %s" % url
             h = urlopen(url)
             r = h.read()
