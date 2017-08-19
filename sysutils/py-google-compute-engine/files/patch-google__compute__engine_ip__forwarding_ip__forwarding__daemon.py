This patch depends on the follow PR from the upsteram project
https://github.com/GoogleCloudPlatform/compute-image-packages/pull/442

--- google_compute_engine/ip_forwarding/ip_forwarding_daemon.py.orig	2017-07-18 16:43:14 UTC
+++ google_compute_engine/ip_forwarding/ip_forwarding_daemon.py
@@ -38,7 +38,7 @@ from google_compute_engine import networ
 
 from google_compute_engine.ip_forwarding import ip_forwarding_utils
 
-LOCKFILE = '/var/lock/google_ip_forwarding.lock'
+LOCKFILE = '/var/spool/lock/google_ip_forwarding.lock'
 
 
 class IpForwardingDaemon(object):
@@ -131,18 +131,18 @@ class IpForwardingDaemon(object):
     Args:
       result: dict, the metadata response with the new network interfaces.
     """
+    ip_addresses = []
     for network_interface in result:
       mac_address = network_interface.get('mac')
       interface = self.network_utils.GetNetworkInterface(mac_address)
-      ip_addresses = []
       if interface:
         ip_addresses.extend(network_interface.get('forwardedIps', []))
         if self.ip_aliases:
           ip_addresses.extend(network_interface.get('ipAliases', []))
-        self._HandleForwardedIps(ip_addresses, interface)
       else:
         message = 'Network interface not found for MAC address: %s.'
         self.logger.warning(message, mac_address)
+    self._HandleForwardedIps(ip_addresses, 'lo' + self.ip_forwarding_utils.proto_id)
 
 
 def main():
