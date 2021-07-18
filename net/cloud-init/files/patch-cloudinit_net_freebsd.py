--- cloudinit/net/freebsd.py.orig	2021-07-05 03:46:41 UTC
+++ cloudinit/net/freebsd.py
@@ -19,12 +19,13 @@ class Renderer(cloudinit.net.bsd.BSDRenderer):
 
     def write_config(self):
         for device_name, v in self.interface_configurations.items():
+            net_config = 'DHCP'
             if isinstance(v, dict):
-                self.set_rc_config_value(
-                    'ifconfig_' + device_name,
-                    v.get('address') + ' netmask ' + v.get('netmask'))
-            else:
-                self.set_rc_config_value('ifconfig_' + device_name, 'DHCP')
+                net_config = v.get('address') + ' netmask ' + v.get('netmask')
+                mtu = v.get('mtu')
+                if mtu:
+                    net_config += (' mtu %d' % mtu)
+            self.set_rc_config_value('ifconfig_' + device_name, net_config)
 
     def start_services(self, run=False):
         if not run:
