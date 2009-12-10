--- xmpp/auth.py.orig	2009-12-10 20:43:19.000000000 +0800
+++ xmpp/auth.py	2009-12-10 20:44:17.000000000 +0800
@@ -21,9 +21,9 @@
 
 from protocol import *
 from client import PlugIn
-import sha,base64,random,dispatcher,re
+import base64,random,dispatcher,re
 
-import md5
+import hashlib 
 def HH(some): return md5.new(some).hexdigest()
 def H(some): return md5.new(some).digest()
 def C(some): return ':'.join(some)
