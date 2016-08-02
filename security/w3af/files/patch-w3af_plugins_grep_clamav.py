--- w3af/plugins/grep/clamav.py.orig	2015-04-07 15:04:48 UTC
+++ w3af/plugins/grep/clamav.py
@@ -20,7 +20,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 """
 import threading
-import clamd
+import pyclamd
 
 # Installed as a clamd dependency by pip
 from six import BytesIO
@@ -55,7 +55,7 @@ class clamav(GrepPlugin):
         
         # User configured settings
         # Default for ubuntu installation
-        self._clamd_socket = '/var/run/clamav/clamd.ctl'
+        self._clamd_socket = '/var/run/clamav/clamd.sock'
 
     def grep(self, request, response):
         """
@@ -113,7 +113,7 @@ class clamav(GrepPlugin):
         """
         try:
             cd = self._get_connection()
-            return cd.ping() == u'PONG'
+            return cd.ping()
         except:
             return False
     
@@ -123,7 +123,7 @@ class clamav(GrepPlugin):
                  Thought about having a connection pool, but it doesn't make
                  much sense; plus it adds complexity due to the threads.
         """
-        return clamd.ClamdUnixSocket(path=self._clamd_socket)
+        return pyclamd.ClamdUnixSocket(self._clamd_socket)
     
     def _get_clamd_version(self):
         """
@@ -145,7 +145,7 @@ class clamav(GrepPlugin):
         
         try:
             cd = self._get_connection()
-            result_dict = cd.instream(BytesIO(body))
+            result_dict = cd.scan_stream(body)
         except Exception, e:
             msg = 'The ClamAV plugin failed to connect to clamd using'\
                   ' the provided unix socket: "%s". Please verify your'\
@@ -185,12 +185,9 @@ class clamav(GrepPlugin):
 
         :return: A namedtuple with the scan result
         """
-        try:
-            signature = result['stream'][1]
-            found = result['stream'][0] == 'FOUND'
-            return ScanResult(found, signature)
-        except:
-            om.out.debug('Invalid response from clamd: %s' % result)
+        signature = result['stream'][1]
+        found = result['stream'][0] == 'FOUND'
+        return ScanResult(found, signature)
 
     def set_options(self, options_list):
         self._clamd_socket = options_list['clamd_socket'].get_value()
@@ -232,4 +229,4 @@ class clamav(GrepPlugin):
         This plugin was sponsored by http://scoresecure.com/ .
         """
 
-ScanResult = namedtuple('ScanResult', ['found', 'signature'])
\ No newline at end of file
+ScanResult = namedtuple('ScanResult', ['found', 'signature'])
