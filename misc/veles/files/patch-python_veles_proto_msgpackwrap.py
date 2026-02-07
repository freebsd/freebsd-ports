- workaround for the incompatibility with newer python's msgpack package:
- TypeError: __init__() got an unexpected keyword argument 'encoding'

--- python/veles/proto/msgpackwrap.py.orig	2021-04-01 00:13:20 UTC
+++ python/veles/proto/msgpackwrap.py
@@ -33,7 +33,7 @@ class MsgpackWrapper(pep487.NewObject):
         self.packer = msgpack.Packer(
             use_bin_type=True, default=MsgpackWrapper.pack_obj)
         self.unpacker = msgpack.Unpacker(
-            encoding='utf-8', ext_hook=MsgpackWrapper.load_obj, max_buffer_size=sys.maxsize)
+            ext_hook=MsgpackWrapper.load_obj, max_buffer_size=sys.maxsize)
 
     @classmethod
     def pack_obj(cls, obj):
