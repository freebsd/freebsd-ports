--- google_compute_engine/network_setup/network_setup.py.orig	2017-09-29 00:21:28 UTC
+++ google_compute_engine/network_setup/network_setup.py
@@ -107,12 +107,18 @@ class NetworkSetup(object):
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
