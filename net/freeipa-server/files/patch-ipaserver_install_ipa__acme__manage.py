--- ipaserver/install/ipa_acme_manage.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/ipa_acme_manage.py
@@ -221,7 +221,7 @@ class IPAACMEManage(AdminTool):
         def run_pki_server(command, directive, prefix, value=None):
             """Take a set of arguments to append to pki-server"""
             args = [
-                'pki-server', command,
+                paths.PKI_SERVER, command,
                 f'{prefix}.{directive}'
             ]
             if value is not None:
@@ -287,7 +287,7 @@ class IPAACMEManage(AdminTool):
                     # external is suffucient for our purposes: C,,
                     tmpdb.trust_root_cert(nickname, EXTERNAL_CA_TRUST_FLAGS)
                 print("Starting job...")
-                args = ['pki', '-C', tmpdb.pwd_file, '-d', tmpdb.secdir,
+                args = [paths.PKI, '-C', tmpdb.pwd_file, '-d', tmpdb.secdir,
                         '-n', ra_nickname,
                         'ca-job-start', 'pruning']
                 logger.debug(args)
