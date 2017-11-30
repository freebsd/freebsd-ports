--- google_compute_engine/ip_forwarding/ip_forwarding_daemon.py.orig	2017-09-14 18:08:49 UTC
+++ google_compute_engine/ip_forwarding/ip_forwarding_daemon.py
@@ -137,20 +137,20 @@ class IpForwardingDaemon(object):
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
         if self.target_instance_ips:
           ip_addresses.extend(network_interface.get('targetInstanceIps', []))
-        self._HandleForwardedIps(ip_addresses, interface)
       else:
         message = 'Network interface not found for MAC address: %s.'
         self.logger.warning(message, mac_address)
+    self._HandleForwardedIps(ip_addresses, 'lo' + self.ip_forwarding_utils.proto_id)
 
 
 def main():
