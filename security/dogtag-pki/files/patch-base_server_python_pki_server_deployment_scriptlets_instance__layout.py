--- base/server/python/pki/server/deployment/scriptlets/instance_layout.py.orig	2026-07-12 10:34:10 UTC
+++ base/server/python/pki/server/deployment/scriptlets/instance_layout.py
@@ -160,15 +160,6 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
 
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
 
@@ -211,31 +202,8 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
             return
 
         if config.str2bool(deployer.mdict['pki_systemd_service_create']):
+            instance.create_rc_service(exist_ok=True)
 
-            user = deployer.mdict['pki_user']
-            group = deployer.mdict['pki_group']
-
-            if user != 'pkiuser' or group != 'pkiuser':
-                deployer.set_systemd_override(
-                    'Service', 'User', user, 'user.conf')
-                deployer.set_systemd_override(
-                    'Service', 'Group', group, 'user.conf')
-
-            deployer.write_systemd_overrides()
-            deployer.systemd.daemon_reload()
-
-            # Link /etc/systemd/system/pki-tomcatd.target.wants/pki-tomcatd@<instance>.service
-            # to /lib/systemd/system/pki-tomcatd@.service
-
-            systemd_service_link = os.path.join(
-                pki.server.instance.PKIInstance.TARGET_WANTS,
-                instance.service_name + '.service')
-
-            instance.symlink(
-                pki.server.instance.PKIInstance.UNIT_FILE,
-                systemd_service_link,
-                exist_ok=True)
-
     def destroy(self, deployer):
 
         instance = self.instance
@@ -246,21 +214,9 @@ class PkiScriptlet(pkiscriptlet.AbstractBasePkiScriptl
 
         logger.info('Removing %s instance', instance.name)
 
-        logger.info('Removing %s', deployer.systemd.systemd_link)
-        pki.util.unlink(link=deployer.systemd.systemd_link,
+        logger.info('Removing %s', instance.rc_script)
+        pki.util.unlink(link=instance.rc_script,
                         force=deployer.force)
-
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
 
         if config.str2bool(deployer.mdict['pki_registry_enable']):
             instance.remove_registry(force=deployer.force)
