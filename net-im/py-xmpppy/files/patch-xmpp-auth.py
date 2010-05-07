--- xmpp/auth.py.orig	2007-08-28 12:03:33.000000000 +0200
+++ xmpp/auth.py	2010-04-23 11:29:16.000000000 +0200
@@ -21,13 +21,23 @@
 
 from protocol import *
 from client import PlugIn
-import sha,base64,random,dispatcher,re
+import base64, random, dispatcher, re, sys
 
-import md5
-def HH(some): return md5.new(some).hexdigest()
-def H(some): return md5.new(some).digest()
 def C(some): return ':'.join(some)
 
+if sys.version_info[0:2] < (2, 6):
+    import sha, md5
+    def _SHA(some): return sha.new(some)
+    def HH(some): return md5.new(some).hexdigest()
+    def H(some): return md5.new(some).digest()
+else:
+    import hashlib
+    """ For python version >= 2.6 """
+    def _SHA(some): return hashlib.sha1(some)
+    def HH(some): return hashlib.md5(some).hexdigest()
+    def h(some): return hashlib.md5(some).digest()
+
+
 class NonSASL(PlugIn):
     """ Implements old Non-SASL (JEP-0078) authentication used in jabberd1.4 and transport authentication."""
     def __init__(self,user,password,resource):
@@ -54,15 +64,15 @@
 
         if query.getTag('digest'):
             self.DEBUG("Performing digest authentication",'ok')
-            query.setTagData('digest',sha.new(owner.Dispatcher.Stream._document_attrs['id']+self.password).hexdigest())
+            query.setTagData('digest', _SHA(owner.Dispatcher.Stream._document_attrs['id']+self.password).hexdigest())
             if query.getTag('password'): query.delChild('password')
             method='digest'
         elif query.getTag('token'):
             token=query.getTagData('token')
             seq=query.getTagData('sequence')
             self.DEBUG("Performing zero-k authentication",'ok')
-            hash = sha.new(sha.new(self.password).hexdigest()+token).hexdigest()
-            for foo in xrange(int(seq)): hash = sha.new(hash).hexdigest()
+            hash = _SHA(_SHA(self.password).hexdigest()+token).hexdigest()
+            for foo in xrange(int(seq)): hash = _SHA(hash).hexdigest()
             query.setTagData('hash',hash)
             method='0k'
         else:
@@ -81,7 +91,7 @@
     def authComponent(self,owner):
         """ Authenticate component. Send handshake stanza and wait for result. Returns "ok" on success. """
         self.handshake=0
-        owner.send(Node(NS_COMPONENT_ACCEPT+' handshake',payload=[sha.new(owner.Dispatcher.Stream._document_attrs['id']+self.password).hexdigest()]))
+        owner.send(Node(NS_COMPONENT_ACCEPT+' handshake',payload=[_SHA(owner.Dispatcher.Stream._document_attrs['id']+self.password).hexdigest()]))
         owner.RegisterHandler('handshake',self.handshakeHandler,xmlns=NS_COMPONENT_ACCEPT)
         while not self.handshake:
             self.DEBUG("waiting on handshake",'notify')

