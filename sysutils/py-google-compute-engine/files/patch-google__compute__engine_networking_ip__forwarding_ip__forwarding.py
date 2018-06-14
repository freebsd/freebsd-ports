--- google_compute_engine/networking/ip_forwarding/ip_forwarding.py.orig	2018-06-11 23:51:09 UTC
+++ google_compute_engine/networking/ip_forwarding/ip_forwarding.py
@@ -85,15 +85,17 @@ class IpForwarding(object):
     for address in forwarded_ips:
       self.ip_forwarding_utils.RemoveForwardedIp(address, interface)
 
-  def HandleForwardedIps(self, interface, forwarded_ips):
+  def HandleForwardedIps(self, interface, forwarded_ips, interface_ip):
     """Handle changes to the forwarded IPs on a network interface.
 
     Args:
       interface: string, the output device to configure.
       forwarded_ips: list, the forwarded IP address strings desired.
+      interface_ip: string, current interface ip address.
     """
     desired = self.ip_forwarding_utils.ParseForwardedIps(forwarded_ips)
-    configured = self.ip_forwarding_utils.GetForwardedIps(interface)
+    configured = self.ip_forwarding_utils.GetForwardedIps(
+        interface, interface_ip)
     to_add = sorted(set(desired) - set(configured))
     to_remove = sorted(set(configured) - set(desired))
     self._LogForwardedIpChanges(
