--- linkcheck/socketutil.py.orig	2009-08-22 22:24:42.000000000 +0200
+++ linkcheck/socketutil.py	2009-08-22 22:25:17.000000000 +0200
@@ -28,9 +28,10 @@
         has_ipv6 = True
     except socket.error, msg:
         # only catch these one:
+	# socket.error: (43, 'Protocol not supported')
         # socket.error: (97, 'Address family not supported by protocol')
         # socket.error: (10047, 'Address family not supported by protocol')
-        if msg.args[0] not in (97, 10047):
+        if msg.args[0] not in (43, 97, 10047):
             raise
 
 
