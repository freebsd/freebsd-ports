--- src/txamqp/codec.py.orig	2009-08-16 11:25:45 UTC
+++ src/txamqp/codec.py
@@ -25,12 +25,12 @@ fields.
 """
 
 from cStringIO import StringIO
-from struct import *
+from struct import pack, calcsize, unpack
 
 class EOF(Exception):
   pass
 
-class Codec:
+class Codec(object):
 
   def __init__(self, stream):
     self.stream = stream
@@ -153,6 +153,13 @@ class Codec:
   def decode_longstr(self):
     return self.dec_str("!L")
 
+  # timestamp
+  def encode_timestamp(self, o):
+    self.pack("!Q", o)
+
+  def decode_timestamp(self):
+    return self.unpack("!Q")
+
   # table
   def encode_table(self, tbl):
     enc = StringIO()
@@ -180,6 +187,10 @@ class Codec:
         value = self.decode_longstr()
       elif type == "I":
         value = self.decode_long()
+      elif type == "F":
+        value = self.decode_table()
+      elif type == "t":
+        value = (self.decode_octet() != 0)
       else:
         raise ValueError(repr(type))
       result[key] = value
