--- base/server/python/pki/server/instance.py.orig	2025-08-05 19:20:05 UTC
+++ base/server/python/pki/server/instance.py
@@ -50,9 +50,6 @@ class PKIInstance(pki.server.PKIServer):
 class PKIInstance(pki.server.PKIServer):
 
     REGISTRY_FILE = pki.server.PKIServer.SHARE_DIR + '/setup/pkidaemon_registry'
-    UNIT_FILE = pki.server.LIB_SYSTEMD_DIR + '/system/pki-tomcatd@.service'
-    TARGET_FILE = pki.server.LIB_SYSTEMD_DIR + '/system/pki-tomcatd.target'
-    TARGET_WANTS = pki.server.ETC_SYSTEMD_DIR + '/system/pki-tomcatd.target.wants'
 
     def __init__(self,
                  name,
@@ -147,9 +144,6 @@ class PKIInstance(pki.server.PKIServer):
             return os.path.join(pki.BASE_DIR, self.name)
         return os.path.join(pki.server.PKIServer.BASE_DIR, self.name)
 
-    @property
-    def service_conf(self):
-        return os.path.join(pki.server.SYSCONFIG_DIR, self.name)
 
     @property
     def server_cert_nick_conf(self):
@@ -175,10 +169,6 @@ class PKIInstance(pki.server.PKIServer):
     def registry_file(self):
         return os.path.join(self.registry_dir, self.name)
 
-    @property
-    def unit_file(self):
-        return PKIInstance.TARGET_WANTS + '/%s.service' % self.service_name
-
     def execute(
             self, command,
             as_current_user=False,
@@ -196,20 +186,24 @@ class PKIInstance(pki.server.PKIServer):
             else:
                 instance_id = '%s@%s' % (self.type, self.name)
 
-            prefix = []
+            subprocess_kwargs = {}
 
-            # by default run pkidaemon as systemd user
+            # by default run commands as service user
             if not as_current_user:
 
                 current_user = pwd.getpwuid(os.getuid()).pw_name
 
-                # switch to systemd user if different from current user
+                # switch to service user if different from current user
                 if current_user != self.user:
-                    prefix.extend(['/usr/sbin/runuser', '-u', self.user, '--'])
+                    subprocess_kwargs.update({
+                        'user': self.user,
+                        'group': self.group,
+                        'extra_groups': os.getgrouplist(self.user, self.gid)
+                    })
 
             if not skip_upgrade:
                 # run pki-server upgrade <instance>
-                cmd = prefix + ['/usr/sbin/pki-server', 'upgrade']
+                cmd = ['/usr/local/sbin/pki-server', 'upgrade']
 
                 if logger.isEnabledFor(logging.DEBUG):
                     cmd.append('--debug')
@@ -220,11 +214,11 @@ class PKIInstance(pki.server.PKIServer):
                 cmd.append(instance_id)
 
                 logger.debug('Command: %s', ' '.join(cmd))
-                subprocess.run(cmd, env=self.config, check=True)
+                subprocess.run(cmd, env=self.config, check=True, **subprocess_kwargs)
 
             if not skip_migration:
                 # run pki-server migrate <instance>
-                cmd = prefix + ['/usr/sbin/pki-server', 'migrate']
+                cmd = ['/usr/local/sbin/pki-server', 'migrate']
 
                 if logger.isEnabledFor(logging.DEBUG):
                     cmd.append('--debug')
@@ -235,13 +229,13 @@ class PKIInstance(pki.server.PKIServer):
                 cmd.append(instance_id)
 
                 logger.debug('Command: %s', ' '.join(cmd))
-                subprocess.run(cmd, env=self.config, check=True)
+                subprocess.run(cmd, env=self.config, check=True, **subprocess_kwargs)
 
             # run pkidaemon start <instance>
-            cmd = prefix + ['/usr/bin/pkidaemon', 'start', instance_id]
+            cmd = ['/usr/local/bin/pkidaemon', 'start', instance_id]
 
             logger.debug('Command: %s', ' '.join(cmd))
-            subprocess.run(cmd, env=self.config, check=True)
+            subprocess.run(cmd, env=self.config, check=True, **subprocess_kwargs)
 
         return super().execute(
             command,
@@ -257,8 +251,6 @@ class PKIInstance(pki.server.PKIServer):
 
         self.create_registry()
 
-        self.symlink(PKIInstance.UNIT_FILE, self.unit_file, exist_ok=True)
-
     def create_libs(self, force=False):
 
         if not self.with_maven_deps:
@@ -400,9 +392,6 @@ class PKIInstance(pki.server.PKIServer):
 
     def remove(self, remove_conf=False, remove_logs=False, force=False):
 
-        logger.info('Removing %s', self.unit_file)
-        pki.util.unlink(self.unit_file, force=force)
-
         self.remove_registry(force=force)
 
         super().remove(
@@ -776,8 +765,6 @@ class PKIInstance(pki.server.PKIServer):
         csr_file = self.csr_file(cert_id)
 
         cmd = [
-            '/usr/sbin/runuser',
-            '-u', self.user, '--',
             'pki',
             '-d', self.nssdb_dir,
             '-f', self.password_conf
@@ -803,7 +790,11 @@ class PKIInstance(pki.server.PKIServer):
 
         logger.debug('Command: %s', ' '.join(cmd))
 
-        subprocess.check_call(cmd)
+        subprocess.check_call(
+            cmd,
+            user=self.user,
+            group=self.group,
+            extra_groups=os.getgrouplist(self.user, self.gid))
 
     def cert_create(
             self, cert_id=None,
@@ -870,8 +861,6 @@ class PKIInstance(pki.server.PKIServer):
             cert_file = self.cert_file(cert_id)
 
             cmd = [
-                '/usr/sbin/runuser',
-                '-u', self.user, '--',
                 'pki',
                 '-d', self.nssdb_dir,
                 '-f', self.password_conf
@@ -900,7 +889,11 @@ class PKIInstance(pki.server.PKIServer):
 
             logger.debug('Command: %s', ' '.join(cmd))
 
-            subprocess.check_call(cmd)
+            subprocess.check_call(
+                cmd,
+                user=self.user,
+                group=self.group,
+                extra_groups=os.getgrouplist(self.user, self.gid))
 
             return
 
