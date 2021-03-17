--- cloudinit/config/cc_salt_minion.py.orig	2021-01-15 17:33:05 UTC
+++ cloudinit/config/cc_salt_minion.py
@@ -46,7 +46,7 @@ specify them with ``pkg_name``, ``service_name`` and `
 import os
 
 from cloudinit import safeyaml, subp, util
-from cloudinit.distros import rhel_util
+from cloudinit.distros import bsd_utils
 
 
 # Note: see https://docs.saltstack.com/en/latest/topics/installation/
@@ -125,8 +141,7 @@ def handle(name, cfg, cloud, log, _args):
     # we need to have the salt minion service enabled in rc in order to be
     # able to start the service. this does only apply on FreeBSD servers.
     if cloud.distro.osfamily == 'freebsd':
-        rhel_util.update_sysconfig_file(
-            '/etc/rc.conf', {'salt_minion_enable': 'YES'})
+        bsd_utils.set_rc_config_value('salt_minion_enable', 'YES')
 
     # restart salt-minion. 'service' will start even if not started. if it
     # was started, it needs to be restarted for config change.
