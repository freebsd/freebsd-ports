--- google_compute_engine/ip_forwarding/ip_forwarding_utils.py.orig	2017-09-14 18:08:49 UTC
+++ google_compute_engine/ip_forwarding/ip_forwarding_utils.py
@@ -17,6 +17,8 @@
 
 import re
 import subprocess
+import netifaces
+import netaddr
 
 IP_REGEX = re.compile(r'\A(\d{1,3}\.){3}\d{1,3}\Z')
 IP_ALIAS_REGEX = re.compile(r'\A(\d{1,3}\.){3}\d{1,3}/\d{1,2}\Z')
@@ -51,8 +53,8 @@ class IpForwardingUtils(object):
     options.update(kwargs)
     return options
 
-  def _RunIpRoute(self, args=None, options=None):
-    """Run a command with ip route and return the response.
+  def _RunIfconfig(self, args=None, options=None):
+    """Run a command with ifconfig and return the response.
 
     Args:
       args: list, the string ip route command args to execute.
@@ -63,7 +65,7 @@ class IpForwardingUtils(object):
     """
     args = args or []
     options = options or {}
-    command = ['ip', 'route']
+    command = ['ifconfig']
     command.extend(args)
     for item in options.items():
       command.extend(item)
@@ -108,10 +110,15 @@ class IpForwardingUtils(object):
     Returns:
       list, the IP address strings.
     """
-    args = ['ls', 'table', 'local', 'type', 'local']
-    options = self._CreateRouteOptions(dev=interface)
-    result = self._RunIpRoute(args=args, options=options)
-    return self.ParseForwardedIps(result.split())
+    try:
+      ips = netifaces.ifaddresses('lo' + self.proto_id)
+      ips = ips[netifaces.AF_INET]
+    except (ValueError, KeyError) as e:
+      return []
+    forwarded_ips = []
+    for ip in ips:
+      forwarded_ips.append(ip['addr'] + '/' + str(netaddr.IPAddress(ip['netmask']).netmask_bits()))
+    return self.ParseForwardedIps(forwarded_ips)
 
   def AddForwardedIp(self, address, interface):
     """Configure a new IP address on the network interface.
@@ -121,9 +128,12 @@ class IpForwardingUtils(object):
       interface: string, the output device to use.
     """
     address = address if IP_ALIAS_REGEX.match(address) else '%s/32' % address
-    args = ['add', 'to', 'local', address]
-    options = self._CreateRouteOptions(dev=interface)
-    self._RunIpRoute(args=args, options=options)
+    cmd = 'alias'
+    try:
+      forwarded_ips = netifaces.ifaddresses(interface)
+    except (ValueError, KeyError) as e:
+      cmd = 'create'
+    self._RunIfconfig(args=[interface, cmd, address])
 
   def RemoveForwardedIp(self, address, interface):
     """Delete an IP address on the network interface.
@@ -132,7 +142,5 @@ class IpForwardingUtils(object):
       address: string, the IP address to configure.
       interface: string, the output device to use.
     """
-    address = address if IP_ALIAS_REGEX.match(address) else '%s/32' % address
-    args = ['delete', 'to', 'local', address]
-    options = self._CreateRouteOptions(dev=interface)
-    self._RunIpRoute(args=args, options=options)
+    address = address if IP_REGEX.match(address) else address[:-3]
+    self._RunIfconfig(args=[interface, '-alias', address])
