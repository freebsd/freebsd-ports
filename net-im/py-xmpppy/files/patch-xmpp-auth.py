--- xmpp/auth.py.orig	2010-04-03 21:45:50.000000000 +0800
+++ xmpp/auth.py	2010-04-03 21:45:56.000000000 +0800
@@ -19,13 +19,13 @@ Provides library with all Non-SASL and S
 Can be used both for client and transport authentication.
 """
 
+from hashlib import md5
 from protocol import *
 from client import PlugIn
-import sha,base64,random,dispatcher,re
+import base64,random,dispatcher,re
 
-import md5
-def HH(some): return md5.new(some).hexdigest()
-def H(some): return md5.new(some).digest()
+def HH(some): return md5(some).hexdigest()
+def H(some): return md5(some).digest()
 def C(some): return ':'.join(some)
 
 class NonSASL(PlugIn):
