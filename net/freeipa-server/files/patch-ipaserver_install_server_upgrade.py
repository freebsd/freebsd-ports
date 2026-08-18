--- ipaserver/install/server/upgrade.py.orig	2026-01-16 09:23:37 UTC
+++ ipaserver/install/server/upgrade.py
@@ -227,7 +227,7 @@ def check_certs():
         else:
             logger.error("Missing Certification Authority file.")
             logger.error("You should place a copy of the CA certificate in "
-                         "/usr/share/ipa/html/ca.crt")
+                         "/usr/local/share/ipa/html/ca.crt")
     else:
         logger.debug('Certificate file exists')
 
@@ -1136,9 +1136,9 @@ def ca_upgrade_schema(ca):
     # ACME schema file moved in pki-server-10.9.0-0.3
     # ACME database connections were abstrated in pki-acme-10.10.0
     for path in [
-        '/usr/share/pki/acme/conf/database/ds/schema.ldif',
-        '/usr/share/pki/acme/conf/database/ldap/schema.ldif',
-        '/usr/share/pki/acme/database/ldap/schema.ldif',
+        '/usr/local/share/pki/acme/conf/database/ds/schema.ldif',
+        '/usr/local/share/pki/acme/conf/database/ldap/schema.ldif',
+        '/usr/local/share/pki/acme/database/ldap/schema.ldif',
     ]:
         if os.path.exists(path):
             acme_schema_ldif = path
@@ -1148,8 +1148,8 @@ def ca_upgrade_schema(ca):
         return False
 
     schema_files=[
-        '/usr/share/pki/server/conf/schema-certProfile.ldif',
-        '/usr/share/pki/server/conf/schema-authority.ldif',
+        '/usr/local/share/pki/server/conf/schema-certProfile.ldif',
+        '/usr/local/share/pki/server/conf/schema-authority.ldif',
         acme_schema_ldif,
     ]
     try:
@@ -1671,6 +1671,7 @@ def upgrade_configuration():
         FQDN=fqdn,
         AUTOREDIR='' if auto_redirect else '#',
         CRL_PUBLISH_PATH=paths.PKI_CA_PUBLISH_DIR,
+        USR_SHARE_IPA_DIR=paths.USR_SHARE_IPA_DIR.rstrip("/"),
         DOGTAG_PORT=8009,
         CLONE='#',
         WSGI_PREFIX_DIR=paths.WSGI_PREFIX_DIR,
