--- google_compute_engine/networking/network_daemon.py.orig	2018-06-11 23:51:09 UTC
+++ google_compute_engine/networking/network_daemon.py
@@ -96,7 +96,7 @@ class NetworkDaemon(object):
     for interface in network_interfaces:
       if self.ip_forwarding_enabled:
         self.ip_forwarding.HandleForwardedIps(
-            interface.name, interface.forwarded_ips)
+            interface.name, interface.forwarded_ips, interface.ip)
 
   def _ExtractInterfaceMetadata(self, metadata):
     """Extracts network interface metadata.
@@ -119,7 +119,8 @@ class NetworkDaemon(object):
         if self.target_instance_ips:
           ip_addresses.extend(network_interface.get('targetInstanceIps', []))
         interfaces.append(NetworkDaemon.NetworkInterface(
-            interface, ip_addresses))
+            interface, ip_addresses, network_interface.get('ip', [])))
+
       else:
         message = 'Network interface not found for MAC address: %s.'
         self.logger.warning(message, mac_address)
@@ -128,9 +129,10 @@ class NetworkDaemon(object):
   class NetworkInterface(object):
     """Network interface information extracted from metadata."""
 
-    def __init__(self, name, forwarded_ips=None):
+    def __init__(self, name, forwarded_ips=None, ip=None):
       self.name = name
       self.forwarded_ips = forwarded_ips
+      self.ip = ip
 
 
 def main():
