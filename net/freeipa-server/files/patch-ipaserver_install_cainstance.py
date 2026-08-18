--- ipaserver/install/cainstance.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/cainstance.py
@@ -719,6 +719,9 @@ class CAInstance(DogtagInstance):
     def add_ipa_wait(self):
         """Add ipa-pki-wait-running to pki-tomcatd service
         """
+        if paths.SYSTEMCTL is None:
+            return
+
         conf = paths.SYSTEMD_PKI_TOMCAT_IPA_CONF
         directory = os.path.dirname(conf)
         if not os.path.isdir(directory):
@@ -1598,7 +1601,7 @@ class CAInstance(DogtagInstance):
             return False
 
         logger.debug('Deploying ACME')
-        self._ldap_mod('/usr/share/pki/acme/database/ds/schema.ldif')
+        self._ldap_mod('/usr/local/share/pki/acme/database/ds/schema.ldif')
 
         configure_acme_acls()
 
@@ -1633,7 +1636,7 @@ class CAInstance(DogtagInstance):
         ensure_acme_containers()
 
         # create ACME service instance
-        ipautil.run(['pki-server', 'acme-create'])
+        ipautil.run([paths.PKI_SERVER, 'acme-create'])
 
         # write configuration files
         sub_dict = dict(
@@ -1651,7 +1654,7 @@ class CAInstance(DogtagInstance):
                 self.service_user.chown(f.fileno())
 
         # deploy ACME Tomcat application
-        ipautil.run(['pki-server', 'acme-deploy'])
+        ipautil.run([paths.PKI_SERVER, 'acme-deploy'])
 
         return True
 
@@ -1908,7 +1911,7 @@ def minimum_acme_support(data=None):
                   reading from the filesystem.
     """
     if not data:
-        with open('/usr/share/pki/VERSION', 'r') as fd:
+        with open('/usr/local/share/pki/VERSION', 'r') as fd:
             data = fd.read()
 
     groups = re.match(r'.*\nSpecification-Version: ([\d+\.]*)\n.*', data)
@@ -2070,9 +2073,9 @@ def __get_profile_config(profile_id):
     # Select UPGRADE version if we are in the 'updates' API context
     # and an upgrade-specific version of the profile exists.
     #
-    profile_filename = '/usr/share/ipa/profiles/{}.cfg'.format(profile_id)
+    profile_filename = '/usr/local/share/ipa/profiles/{}.cfg'.format(profile_id)
     profile_upg_filename = \
-        '/usr/share/ipa/profiles/{}.UPGRADE.cfg'.format(profile_id)
+        '/usr/local/share/ipa/profiles/{}.UPGRADE.cfg'.format(profile_id)
     if api.env.context == 'updates' and os.path.isfile(profile_upg_filename):
         profile_filename = profile_upg_filename
 
