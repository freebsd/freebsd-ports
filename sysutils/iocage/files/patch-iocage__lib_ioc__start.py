Originates here
https://github.com/iocage/iocage/commit/753b2f35731423597d7f51f33427b6d619fcd0b5
https://github.com/iocage/iocage/pull/1106
and most likely can be removed on the next release of iocage.
--- iocage_lib/ioc_start.py.orig	2019-09-26 07:23:24 UTC
+++ iocage_lib/ioc_start.py
@@ -145,7 +145,6 @@ class IOCStart(object):
         allow_quotas = self.conf["allow_quotas"]
         allow_socket_af = self.conf["allow_socket_af"]
         allow_vmm = self.conf["allow_vmm"]
-        devfs_ruleset = iocage_lib.ioc_common.generate_devfs_ruleset(self.conf)
         exec_prestart = self.conf["exec_prestart"]
         exec_poststart = self.conf["exec_poststart"]
         exec_clean = self.conf["exec_clean"]
@@ -486,16 +485,8 @@ class IOCStart(object):
             _callback=self.callback,
             silent=self.silent)
 
-        if wants_dhcp and self.conf['type'] != 'pluginv2' \
-                and self.conf['devfs_ruleset'] != '4':
-            iocage_lib.ioc_common.logit({
-                "level": "WARNING",
-                "message": f"  {self.uuid} is not using the devfs_ruleset"
-                           f" of 4, not generating a ruleset for the jail,"
-                           " DHCP may not work."
-            },
-                _callback=self.callback,
-                silent=self.silent)
+        devfs_paths = None
+        devfs_includes = None
 
         if self.conf['type'] == 'pluginv2' and os.path.isfile(
             os.path.join(self.path, f'{self.conf["plugin_name"]}.json')
@@ -509,17 +500,51 @@ class IOCStart(object):
                     plugin_name = self.conf['plugin_name']
                     plugin_devfs = devfs_json[
                         "devfs_ruleset"][f"plugin_{plugin_name}"]
-                    plugin_devfs_paths = plugin_devfs['paths']
-
-                    plugin_devfs_includes = None if 'includes' not in \
+                    devfs_paths = plugin_devfs['paths']
+                    devfs_includes = None if 'includes' not in \
                         plugin_devfs else plugin_devfs['includes']
 
-                    devfs_ruleset = \
-                        iocage_lib.ioc_common.generate_devfs_ruleset(
-                            self.conf,
-                            paths=plugin_devfs_paths,
-                            includes=plugin_devfs_includes
-                        )
+        # Generate dynamic devfs ruleset from configured one
+        (manual_devfs_config, configured_devfs_ruleset, devfs_ruleset) \
+            = iocage_lib.ioc_common.generate_devfs_ruleset(
+                self.conf, devfs_paths, devfs_includes)
+
+        if int(devfs_ruleset) <= 0:
+            iocage_lib.ioc_common.logit({
+                "level": "ERROR",
+                "message": f"{self.uuid} devfs_ruleset"
+                           f" {configured_devfs_ruleset} does not exist!"
+                           " - Not starting jail"
+            },
+                _callback=self.callback,
+                silent=self.silent)
+            return
+
+        # Manually configured devfs_ruleset doesn't support all iocage features
+        if manual_devfs_config:
+            if devfs_paths is not None or devfs_includes is not None:
+                iocage_lib.ioc_common.logit({
+                    "level": "WARNING",
+                    "message": f"  {self.uuid} is not using the devfs_ruleset"
+                               " of "
+                               f"{iocage_lib.ioc_common.IOCAGE_DEVFS_RULESET}"
+                               ", devices and includes from plugin not added"
+                               ", some features of the plugin may not work."
+                },
+                    _callback=self.callback,
+                    silent=self.silent)
+
+            if wants_dhcp and self.conf['type'] != 'pluginv2':
+                iocage_lib.ioc_common.logit({
+                    "level": "WARNING",
+                    "message": f"  {self.uuid} is not using the devfs_ruleset"
+                               " of "
+                               f"{iocage_lib.ioc_common.IOCAGE_DEVFS_RULESET}"
+                               ", not generating a ruleset for the jail,"
+                               " DHCP may not work."
+                },
+                    _callback=self.callback,
+                    silent=self.silent)
 
         parameters = [
             fdescfs, _allow_mlock, tmpfs,
@@ -619,6 +644,9 @@ class IOCStart(object):
         iocage_lib.ioc_common.logit({
             'level': 'INFO',
             'message': f'  + Using devfs_ruleset: {devfs_ruleset}'
+                       + (' (cloned from devfs_ruleset '
+                          f'{configured_devfs_ruleset})' if manual_devfs_config
+                          else ' (iocage generated default)')
         },
             _callback=self.callback,
             silent=self.silent)
