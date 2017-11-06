dhclient works a bit different in BSD compared to Linux, this patch adapts its usage.

--- google_compute_engine/network_setup/network_setup.py.orig	2017-07-23 07:12:16 UTC
+++ google_compute_engine/network_setup/network_setup.py
@@ -74,7 +74,7 @@ class NetworkSetup(object):
     Args:
       interfaces: list of string, the output device names enable.
     """
-    interface_path = '/etc/sysconfig/network-scripts'
+    interface_path = '%%PREFIX%%/etc/sysconfig/network-scripts'
     for interface in interfaces:
       interface_config = os.path.join(interface_path, 'ifcfg-%s' % interface)
       if os.path.exists(interface_config):
@@ -106,12 +106,18 @@ class NetworkSetup(object):
     self.logger.info('Enabling the Ethernet interfaces %s.', interfaces)
     dhclient_command = ['dhclient']
     if os.path.exists(self.dhclient_script):
-      dhclient_command += ['-sf', self.dhclient_script]
-    try:
-      subprocess.check_call(dhclient_command + ['-x'] + interfaces)
-      subprocess.check_call(dhclient_command + interfaces)
-    except subprocess.CalledProcessError:
-      self.logger.warning('Could not enable interfaces %s.', interfaces)
+      dhclient_conf = '/etc/dhclient.conf'
+      if os.path.exists(dhclient_conf):
+        subprocess.call('sed -i "" "/^script/d" ' + dhclient_conf, shell=True)
+      subprocess.call('echo \'script "%s";\' >> %s' % (self.dhclient_script, dhclient_conf), shell=True)
+    for interface in interfaces:
+      try:
+        subprocess.check_call(['ifconfig', interface, 'down', 'delete'])
+        # wait previous dhclient to exit
+        subprocess.check_call(['sleep', '3'])
+        subprocess.check_call(dhclient_command + [interface])
+      except subprocess.CalledProcessError:
+        self.logger.warning('Could not enable interface %s.', interface)
 
   def _EnableNetworkInterfaces(self, interfaces):
     """Enable the list of network interfaces.
@@ -130,7 +136,7 @@ class NetworkSetup(object):
       except subprocess.CalledProcessError:
         self.logger.warning('Could not enable Ethernet interfaces.')
     else:
-      if os.path.exists('/etc/sysconfig/network-scripts'):
+      if os.path.exists('%%PREFIX%%/etc/sysconfig/network-scripts'):
         self._DisableNetworkManager(interfaces)
       self._ConfigureNetwork(interfaces)
 
