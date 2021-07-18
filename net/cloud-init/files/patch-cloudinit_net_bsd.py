--- cloudinit/net/bsd.py.orig	2021-07-05 03:47:58 UTC
+++ cloudinit/net/bsd.py
@@ -33,7 +33,7 @@ class BSDRenderer(renderer.Renderer):
         self.interface_configurations = {}
         self._postcmds = config.get('postcmds', True)
 
-    def _ifconfig_entries(self, settings, target=None):
+    def _ifconfig_entries(self, settings):
         ifname_by_mac = net.get_interfaces_by_mac()
         for interface in settings.iter_interfaces():
             device_name = interface.get("name")
@@ -76,9 +76,10 @@ class BSDRenderer(renderer.Renderer):
                     self.interface_configurations[device_name] = {
                         'address': subnet.get('address'),
                         'netmask': subnet.get('netmask'),
+                        'mtu': subnet.get('mtu') or interface.get('mtu'),
                     }
 
-    def _route_entries(self, settings, target=None):
+    def _route_entries(self, settings):
         routes = list(settings.iter_routes())
         for interface in settings.iter_interfaces():
             subnets = interface.get("subnets", [])
@@ -101,7 +102,7 @@ class BSDRenderer(renderer.Renderer):
             gateway = route.get('gateway')
             self.set_route(network, netmask, gateway)
 
-    def _resolve_conf(self, settings, target=None):
+    def _resolve_conf(self, settings):
         nameservers = settings.dns_nameservers
         searchdomains = settings.dns_searchdomains
         for interface in settings.iter_interfaces():
@@ -114,11 +115,11 @@ class BSDRenderer(renderer.Renderer):
         # fails.
         try:
             resolvconf = ResolvConf(util.load_file(subp.target_path(
-                target, self.resolv_conf_fn)))
+                self.target, self.resolv_conf_fn)))
             resolvconf.parse()
         except IOError:
             util.logexc(LOG, "Failed to parse %s, use new empty file",
-                        subp.target_path(target, self.resolv_conf_fn))
+                        subp.target_path(self.target, self.resolv_conf_fn))
             resolvconf = ResolvConf('')
             resolvconf.parse()
 
@@ -136,10 +137,12 @@ class BSDRenderer(renderer.Renderer):
             except ValueError:
                 util.logexc(LOG, "Failed to add search domain %s", domain)
         util.write_file(
-            subp.target_path(target, self.resolv_conf_fn),
+            subp.target_path(self.target, self.resolv_conf_fn),
             str(resolvconf), 0o644)
 
     def render_network_state(self, network_state, templates=None, target=None):
+        if target:
+            self.target = target
         self._ifconfig_entries(settings=network_state)
         self._route_entries(settings=network_state)
         self._resolve_conf(settings=network_state)
