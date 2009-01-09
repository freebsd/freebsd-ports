--- pyclamd.py.orig	2007-04-11 18:10:26.000000000 +0200
+++ pyclamd.py	2007-08-28 11:28:48.000000000 +0200
@@ -14,7 +14,7 @@
     # Network
     pyclamd.init_network_socket('localhost', 3310)
     # Unix local socket 
-    #pyclamd.init_unix_socket('/var/run/clamd')
+    #pyclamd.init_unix_socket('/var/run/clamav/clamd')
 
     # Get Clamscan version
     print pyclamd.version()
@@ -29,7 +29,7 @@
 Test strings :
 ^^^^^^^^^^^^
 >>> try:
-...     init_unix_socket('/var/run/clamd')
+...     init_unix_socket('/var/run/clamav/clamd')
 ... except ScanError:
 ...     init_network_socket('localhost', 3310)
 ... 
@@ -68,7 +68,7 @@
 
 # Default values for globals
 use_socket = None
-clamd_SOCKET = "/var/run/clamd"
+clamd_SOCKET = "/var/run/clamav/clamd"
 clamd_HOST='127.0.0.1'
 clamd_PORT=3310
 
@@ -85,7 +85,7 @@
             
 ############################################################################
 
-def init_unix_socket(filename="/var/run/clamd"):
+def init_unix_socket(filename="/var/run/clamav/clamd"):
     """
     Init pyclamd to use clamd unix local socket 
     
