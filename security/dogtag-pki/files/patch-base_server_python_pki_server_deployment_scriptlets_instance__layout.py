--- base/server/python/pki/server/deployment/scriptlets/instance_layout.py.orig	2026-07-28 16:37:15 UTC
+++ base/server/python/pki/server/deployment/scriptlets/instance_layout.py
@@ -163,15 +163,6 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
 
         deployer.create_server_nssdb()
 
-        # Copy /usr/share/pki/server/conf/tomcat.conf
-        # to /etc/sysconfig/<instance>
-
-        instance.copyfile(
-            os.path.join(shared_conf_path, 'tomcat.conf'),
-            instance.service_conf,
-            params=deployer.mdict,
-            exist_ok=True)
-
         # Copy /usr/share/pki/server/conf/tomcat.conf to
         # /var/lib/pki/<instance>/conf/tomcat.conf.
 
@@ -215,18 +206,8 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
 
         if config.str2bool(deployer.mdict['pki_systemd_service_create']):
 
-            user = deployer.mdict['pki_user']
-            group = deployer.mdict['pki_group']
+            instance.create_rc_service(exist_ok=True)
 
-            if user != 'pkiuser' or group != 'pkiuser':
-                deployer.set_systemd_override(
-                    'Service', 'User', user, 'user.conf')
-                deployer.set_systemd_override(
-                    'Service', 'Group', group, 'user.conf')
-
-            deployer.write_systemd_overrides()
-            deployer.systemd.daemon_reload()
-
             # Optionally, programmatically 'enable' the configured PKI instance
             # to be started upon system boot (default is True)
 
@@ -263,17 +244,7 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
         '''  # noqa: E501
         instance.disable()
 
-        if os.path.exists(deployer.systemd.base_override_dir):
-            logger.info('Removing %s', deployer.systemd.base_override_dir)
-            pki.util.rmtree(path=deployer.systemd.base_override_dir,
-                            force=deployer.force)
-
-        if os.path.exists(deployer.systemd.nuxwdog_override_dir):
-            logger.info('Removing %s', deployer.systemd.nuxwdog_override_dir)
-            pki.util.rmtree(path=deployer.systemd.nuxwdog_override_dir,
-                            force=deployer.force)
-
-        deployer.systemd.daemon_reload()
+        instance.remove_rc_service(force=deployer.force)
 
         logger.info('Removing %s instance', instance.name)
         instance.remove(
