--- ibus/common.py.orig	2011-08-14 19:14:42.000000000 -0400
+++ ibus/common.py	2012-01-09 13:56:36.000000000 -0500
@@ -104,7 +104,7 @@
 #         return None
 #     return address
 
-libibus = ctypes.CDLL("libibus-1.0.so.0")
+libibus = ctypes.CDLL("libibus-1.0.so.401")
 get_address = libibus.ibus_get_address
 get_address.restype=ctypes.c_char_p
 
