--- ipaserver/install/httpinstance.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/httpinstance.py
@@ -102,6 +102,7 @@ class HTTPInstance(service.Service):
             DOMAIN=self.domain,
             AUTOREDIR='' if auto_redirect else '#',
             CRL_PUBLISH_PATH=paths.PKI_CA_PUBLISH_DIR,
+            USR_SHARE_IPA_DIR=paths.USR_SHARE_IPA_DIR.rstrip("/"),
             FONTS_DIR=paths.FONTS_DIR,
             FONTS_OPENSANS_DIR=paths.FONTS_OPENSANS_DIR,
             FONTS_FONTAWESOME_DIR=paths.FONTS_FONTAWESOME_DIR,
@@ -171,12 +172,49 @@ class HTTPInstance(service.Service):
         # Clean up existing ccaches
         # Make sure that empty env is passed to avoid passing KRB5CCNAME from
         # current env
+        if paths.SYSTEMD_TMPFILES is None:
+            shutil.rmtree(paths.IPA_CCACHES, ignore_errors=True)
+            runtime_dir = os.path.dirname(paths.IPA_CCACHES)
+            os.makedirs(runtime_dir, mode=0o711, exist_ok=True)
+            os.chown(runtime_dir, 0, 0)
+            os.chmod(runtime_dir, 0o711)
+            os.makedirs(paths.IPA_CCACHES, mode=0o770, exist_ok=True)
+            os.chown(
+                paths.IPA_CCACHES,
+                constants.IPAAPI_USER.uid,
+                # FreeBSD: the httpd worker (www) writes the delegated
+                # GSSAPI ccaches here; www is a member of the ipaapi group,
+                # so group-own the dir by ipaapi (setgid) and the ipaapi
+                # wsgi process can then read those ccaches (krb5 allows
+                # group access; otherwise it fails with KRB5_FCC_PERM).
+                constants.IPAAPI_GROUP.gid,
+            )
+            os.chmod(paths.IPA_CCACHES, 0o6770)
+            # Ports only set www's ipaapi-group membership when the group
+            # is first created; enforce it so the httpd worker (www) can
+            # write the delegated GSSAPI ccaches into this ipaapi-group
+            # directory (otherwise mod_auth_gssapi returns 401).
+            tasks.add_user_to_group(
+                constants.HTTPD_USER, constants.IPAAPI_GROUP
+            )
+            # FreeBSD has no systemd-tmpfiles to pre-create the mod_wsgi
+            # socket directory (parent of WSGI_PREFIX_DIR).  Create it
+            # world-traversable so the httpd worker user can reach the
+            # daemon sockets; otherwise /ipa returns HTTP 503 (mod_wsgi
+            # "Unable to connect to WSGI daemon process").
+            wsgi_run_dir = os.path.dirname(paths.WSGI_PREFIX_DIR)
+            os.makedirs(wsgi_run_dir, mode=0o755, exist_ok=True)
+            os.chown(wsgi_run_dir, 0, 0)
+            os.chmod(wsgi_run_dir, 0o755)
+            return
         shutil.rmtree(paths.IPA_CCACHES)
         ipautil.run(
             [paths.SYSTEMD_TMPFILES, '--create', '--prefix', paths.IPA_CCACHES]
         )
 
     def enable_ccache_sweep(self):
+        if paths.SYSTEMCTL is None:
+            return
         ipautil.run(
             [paths.SYSTEMCTL, 'enable', 'ipa-ccache-sweep.timer']
         )
@@ -390,6 +428,12 @@ class HTTPInstance(service.Service):
         directivesetter.set_directive(paths.HTTPD_SSL_SITE_CONF,
                                    'SSLCertificateKeyFile',
                                    paths.HTTPD_KEY_FILE, False)
+        # FreeBSD: the apache sample vhost ships ServerName www.example.com;
+        # mod_ssl passes that name to the SSLPassPhraseDialog exec helper, so
+        # it must be the real host or the httpd key passphrase is not found.
+        directivesetter.set_directive(paths.HTTPD_SSL_SITE_CONF,
+                                      'ServerName',
+                                      '{}:443'.format(api.env.host), False)
         directivesetter.set_directive(
             paths.HTTPD_SSL_CONF,
             'SSLPassPhraseDialog',
@@ -404,6 +448,11 @@ class HTTPInstance(service.Service):
                                    MOD_SSL_VERIFY_DEPTH,
                                    quotes=False)
 
+        # FreeBSD: httpd auto-loads only Includes/*.conf, not extra/;
+        # link the IPA mod_ssl vhost into Includes/ so the 443 vhost loads.
+        ipautil.remove_file(paths.HTTPD_IPA_SSL_CONF_SYMLINK)
+        os.symlink(paths.HTTPD_SSL_CONF, paths.HTTPD_IPA_SSL_CONF_SYMLINK)
+
     def __publish_ca_cert(self):
         ca_subject = self.cert.issuer
         certlist = x509.load_certificate_list_from_file(paths.IPA_CA_CRT)
@@ -426,7 +475,10 @@ class HTTPInstance(service.Service):
     def create_kdcproxy_conf(self):
         """Create ipa-kdc-proxy.conf in /etc/ipa/kdcproxy"""
         target_fname = paths.HTTPD_IPA_KDCPROXY_CONF
-        sub_dict = dict(KDCPROXY_CONFIG=paths.KDCPROXY_CONFIG)
+        sub_dict = dict(
+            KDCPROXY_CONFIG=paths.KDCPROXY_CONFIG,
+            USR_SHARE_IPA_DIR=paths.USR_SHARE_IPA_DIR.rstrip("/"),
+        )
         http_txt = ipautil.template_file(
             os.path.join(paths.USR_SHARE_IPA_DIR,
                          "ipa-kdc-proxy.conf.template"),
@@ -498,6 +550,8 @@ class HTTPInstance(service.Service):
             except ValueError as error:
                 logger.debug("%s", error)
 
+        tasks.remove_httpd_service_ipa_conf()
+
         # Remove the configuration files we create
         ipautil.remove_keytab(self.keytab)
         remove_files = [
@@ -508,6 +562,7 @@ class HTTPInstance(service.Service):
             paths.HTTPD_IPA_CONF,
             paths.HTTPD_IPA_PKI_PROXY_CONF,
             paths.HTTPD_IPA_KDCPROXY_CONF_SYMLINK,
+            paths.HTTPD_IPA_SSL_CONF_SYMLINK,
             paths.HTTPD_IPA_KDCPROXY_CONF,
             paths.GSSPROXY_CONF,
             paths.GSSAPI_SESSION_KEY,
@@ -545,13 +600,15 @@ class HTTPInstance(service.Service):
         if enabled:
             self.enable()
 
-        ipautil.run(
-            [paths.SYSTEMCTL, 'disable', 'ipa-ccache-sweep.timer']
-        )
+        if paths.SYSTEMCTL is not None:
+            ipautil.run(
+                [paths.SYSTEMCTL, 'disable', 'ipa-ccache-sweep.timer']
+            )
         ipautil.remove_file(paths.IPA_CCACHE_SWEEPER_GSSPROXY_SOCK)
 
-        for filename in os.listdir(paths.IPA_CCACHES):
-            ipautil.remove_file(os.path.join(paths.IPA_CCACHES, filename))
+        if os.path.isdir(paths.IPA_CCACHES):
+            for filename in os.listdir(paths.IPA_CCACHES):
+                ipautil.remove_file(os.path.join(paths.IPA_CCACHES, filename))
 
     def stop_tracking_certificates(self):
         try:
