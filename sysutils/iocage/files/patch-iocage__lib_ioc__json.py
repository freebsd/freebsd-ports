Originates here
https://github.com/iocage/iocage/commit/753b2f35731423597d7f51f33427b6d619fcd0b5
https://github.com/iocage/iocage/pull/1106
and most likely can be removed on the next release of iocage.
--- iocage_lib/ioc_json.py.orig	2019-09-26 07:23:24 UTC
+++ iocage_lib/ioc_json.py
@@ -671,7 +671,7 @@ class IOCConfiguration(IOCZFS):
     @staticmethod
     def get_version():
         """Sets the iocage configuration version."""
-        version = '26'
+        version = '27'
 
         return version
 
@@ -1104,6 +1104,10 @@ class IOCConfiguration(IOCZFS):
             if conf.get(option) == 'none':
                 conf[option] = 'auto'
 
+        # Version 27 key
+        if not conf.get('min_dyn_devfs_ruleset'):
+            conf['min_dyn_devfs_ruleset'] = '1000'
+
         if not default:
             conf.update(jail_conf)
 
@@ -1321,7 +1325,7 @@ class IOCConfiguration(IOCZFS):
             'vnet2_mac': 'none',
             'vnet3_mac': 'none',
             'vnet_default_interface': 'auto',
-            'devfs_ruleset': '4',
+            'devfs_ruleset': str(iocage_lib.ioc_common.IOCAGE_DEVFS_RULESET),
             'exec_start': '/bin/sh /etc/rc',
             'exec_stop': '/bin/sh /etc/rc.shutdown',
             'exec_prestart': '/usr/bin/true',
@@ -1432,6 +1436,7 @@ class IOCConfiguration(IOCZFS):
             'nat_forwards': 'none',
             'plugin_name': 'none',
             'plugin_repository': 'none',
+            'min_dyn_devfs_ruleset': '1000',
         }
 
     def check_default_config(self):
@@ -2369,6 +2374,7 @@ class IOCJson(IOCConfiguration):
             'nat_forwards': ('string', ),
             'plugin_name': ('string', ),
             'plugin_repository': ('string', ),
+            'min_dyn_devfs_ruleset': ('string', ),
         }
 
         zfs_props = {
@@ -2648,6 +2654,22 @@ class IOCJson(IOCConfiguration):
                                 silent=self.silent,
                                 exception=ioc_exceptions.ValidationFailed
                             )
+                elif key in ('devfs_ruleset', 'min_dyn_devfs_ruleset'):
+                    try:
+                        intval = int(value)
+                        if intval <= 0:
+                            raise ValueError()
+                        conf[key] = str(intval)
+                    except ValueError:
+                        iocage_lib.ioc_common.logit(
+                            {
+                                'level': 'EXCEPTION',
+                                'message': f'Invalid {key} value: {value}'
+                            },
+                            _callback=self.callback,
+                            silent=self.silent,
+                            exception=ioc_exceptions.ValidationFailed
+                        )
 
                 return value, conf
             else:
