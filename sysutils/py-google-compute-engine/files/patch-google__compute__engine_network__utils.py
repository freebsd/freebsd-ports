This patch depends on the follow PR from the upsteram project
https://github.com/GoogleCloudPlatform/compute-image-packages/pull/442

--- google_compute_engine/network_utils.py.orig	2017-07-18 16:43:14 UTC
+++ google_compute_engine/network_utils.py
@@ -17,6 +17,7 @@
 
 import logging
 import os
+import netifaces
 
 
 class NetworkUtils(object):
@@ -38,11 +39,12 @@ class NetworkUtils(object):
       dict, string MAC addresses mapped to the string network interface name.
     """
     interfaces = {}
-    for interface in os.listdir('/sys/class/net'):
+    for interface in netifaces.interfaces():
       try:
-        mac_address = open(
-            '/sys/class/net/%s/address' % interface).read().strip()
-      except (IOError, OSError) as e:
+        mac_address = netifaces.ifaddresses(interface)[netifaces.AF_LINK][0]['addr']
+        if  mac_address == interface:
+            raise Exception('No MAC Address')
+      except Exception as e:
         message = 'Unable to determine MAC address for %s. %s.'
         self.logger.warning(message, interface, str(e))
       else:
