--- google_compute_engine/networking/ip_forwarding/ip_forwarding_utils.py.orig	2018-06-11 23:51:09 UTC
+++ google_compute_engine/networking/ip_forwarding/ip_forwarding_utils.py
@@ -15,6 +15,8 @@
 
 """Utilities for configuring IP address forwarding."""
 
+import netaddr
+import netifaces
 import re
 import subprocess
 
@@ -32,27 +34,11 @@ class IpForwardingUtils(object):
       logger: logger object, used to write to SysLog and serial port.
       proto_id: string, the routing protocol identifier for Google IP changes.
     """
-    self.logger = logger
-    self.proto_id = proto_id or '66'
 
-  def _CreateRouteOptions(self, **kwargs):
-    """Create a dictionary of parameters to append to the ip route command.
-
-    Args:
-      **kwargs: dict, the string parameters to update in the ip route command.
-
-    Returns:
-      dict, the string parameters to append to the ip route command.
-    """
-    options = {
-        'proto': self.proto_id,
-        'scope': 'host',
-    }
-    options.update(kwargs)
-    return options
+    self.logger = logger
 
-  def _RunIpRoute(self, args=None, options=None):
-    """Run a command with ip route and return the response.
+  def _RunIfconfig(self, args=None, options=None):
+    """Run a command with ifconfig and return the response.
 
     Args:
       args: list, the string ip route command args to execute.
@@ -63,7 +49,7 @@ class IpForwardingUtils(object):
     """
     args = args or []
     options = options or {}
-    command = ['ip', 'route']
+    command = ['ifconfig']
     command.extend(args)
     for item in options.items():
       command.extend(item)
@@ -94,25 +80,33 @@ class IpForwardingUtils(object):
     forwarded_ips = forwarded_ips or []
     for ip in forwarded_ips:
       if ip and (IP_REGEX.match(ip) or IP_ALIAS_REGEX.match(ip)):
-        addresses.append(ip[:-3] if ip.endswith('/32') else ip)
+        addresses.extend([str(addr) for addr in list(netaddr.IPNetwork(ip))])
       else:
         self.logger.warning('Could not parse IP address: "%s".', ip)
     return addresses
 
-  def GetForwardedIps(self, interface):
+  def GetForwardedIps(self, interface, interface_ip):
     """Retrieve the list of configured forwarded IP addresses.
 
     Args:
       interface: string, the output device to query.
+      interface_ip: string, current interface ip address.
 
     Returns:
       list, the IP address strings.
     """
-    args = ['ls', 'table', 'local', 'type', 'local']
-    options = self._CreateRouteOptions(dev=interface)
-    result = self._RunIpRoute(args=args, options=options)
-    result = re.sub(r'local\s', r'', result)
-    return self.ParseForwardedIps(result.split())
+    try:
+      ips = netifaces.ifaddresses(interface)
+      ips = ips[netifaces.AF_INET]
+    except (ValueError, IndexError):
+      return []
+    forwarded_ips = []
+    for ip in ips:
+      if ip['addr'] != interface_ip:
+        forwarded_ips.append(
+            '%s/%d' % (ip['addr'],
+            netaddr.IPAddress(ip['netmask']).netmask_bits()))
+    return self.ParseForwardedIps(forwarded_ips)
 
   def AddForwardedIp(self, address, interface):
     """Configure a new IP address on the network interface.
@@ -121,10 +115,8 @@ class IpForwardingUtils(object):
       address: string, the IP address to configure.
       interface: string, the output device to use.
     """
-    address = address if IP_ALIAS_REGEX.match(address) else '%s/32' % address
-    args = ['add', 'to', 'local', address]
-    options = self._CreateRouteOptions(dev=interface)
-    self._RunIpRoute(args=args, options=options)
+    for ip in list(netaddr.IPNetwork(address)):
+      self._RunIfconfig(args=[interface, 'alias', '%s/32' % str(ip)])
 
   def RemoveForwardedIp(self, address, interface):
     """Delete an IP address on the network interface.
@@ -133,7 +125,5 @@ class IpForwardingUtils(object):
       address: string, the IP address to configure.
       interface: string, the output device to use.
     """
-    address = address if IP_ALIAS_REGEX.match(address) else '%s/32' % address
-    args = ['delete', 'to', 'local', address]
-    options = self._CreateRouteOptions(dev=interface)
-    self._RunIpRoute(args=args, options=options)
+    ip = netaddr.IPNetwork(address)
+    self._RunIfconfig(args=[interface, '-alias', str(ip.ip)])
