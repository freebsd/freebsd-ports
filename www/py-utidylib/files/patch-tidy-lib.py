--- tidy/lib.py.orig	2004-02-24 08:12:24.000000000 +0100
+++ tidy/lib.py	2009-07-08 15:16:11.000000000 +0200
@@ -129,6 +129,7 @@
         return sink
 
 sinkfactory=SinkFactory()
+_tidy.Create.restype = ctypes.POINTER(ctypes.c_void_p)
 
 class _Document(object):
     def __init__(self):
