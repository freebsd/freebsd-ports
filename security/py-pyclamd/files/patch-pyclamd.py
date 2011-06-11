--- pyclamd.py.orig	2011-01-26 20:08:38.000000000 +0100
+++ pyclamd.py	2011-01-26 20:14:58.000000000 +0100
@@ -51,7 +51,7 @@
 	# Network
 	pyclamd.init_network_socket('localhost', 3310)
 	# Unix local socket 
-	#pyclamd.init_unix_socket('/var/run/clamd')
+	#pyclamd.init_unix_socket('/var/run/clamav/clamd.sock')
 
 	# Get Clamscan version
 	print pyclamd.version()
@@ -66,7 +66,7 @@
 Test strings :
 ^^^^^^^^^^^^
 >>> try:
-...	 init_unix_socket('/var/run/clamav/clamd.ctl')
+...	 init_unix_socket('/var/run/clamav/clamd.sock')
 ... except ScanError:
 ...	 init_network_socket('localhost', 3310)
 ... 
@@ -110,7 +110,7 @@
 
 # Default values for globals
 use_socket = None
-clamd_SOCKET = "/var/run/clamav/clamd.ctl"
+clamd_SOCKET = "/var/run/clamav/clamd.sock"
 clamd_HOST = '127.0.0.1'
 clamd_PORT = 3310
 clamd_timeout = None	#[PL] default timeout for sockets: None = blocking operations
@@ -121,7 +121,7 @@
 
 ############################################################################
 
-def init_unix_socket(filename="/var/run/clamav/clamd.ctl"):
+def init_unix_socket(filename="/var/run/clamav/clamd.sock"):
 	"""
 	Init pyclamd to use clamd unix local socket 
 	
