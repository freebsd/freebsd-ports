--- base/server/python/pki/server/cli/acme.py.orig	2026-07-28 16:37:15 UTC
+++ base/server/python/pki/server/cli/acme.py
@@ -440,7 +440,7 @@ class ACMEMetadataShowCLI(pki.cli.CLI):
         config = {}
 
         if not os.path.exists(metadata_conf):
-            source = '/usr/share/pki/acme/conf/metadata.conf'
+            source = '/usr/local/share/pki/acme/conf/metadata.conf'
         else:
             source = metadata_conf
 
@@ -527,7 +527,7 @@ class ACMEMetadataModifyCLI(pki.cli.CLI):
         config = {}
 
         if not os.path.exists(metadata_conf):
-            source = '/usr/share/pki/acme/conf/metadata.conf'
+            source = '/usr/local/share/pki/acme/conf/metadata.conf'
         else:
             source = metadata_conf
 
@@ -901,7 +901,7 @@ class ACMEDatabaseModifyCLI(pki.cli.CLI):
             pki.server.subsystem.ACME_DATABASE_CLASSES.get(database_type))
 
         if orig_database_type != database_type:
-            source = '/usr/share/pki/acme/database/{0}/database.conf'.format(database_type)
+            source = '/usr/local/share/pki/acme/database/{0}/database.conf'.format(database_type)
             logger.info('Loading %s', source)
             pki.util.load_properties(source, config)
 
@@ -1321,7 +1321,7 @@ class ACMEIssuerModifyCLI(pki.cli.CLI):
             pki.server.subsystem.ACME_ISSUER_CLASSES.get(issuer_type))
 
         if orig_issuer_type != issuer_type:
-            source = '/usr/share/pki/acme/issuer/{0}/issuer.conf'.format(issuer_type)
+            source = '/usr/local/share/pki/acme/issuer/{0}/issuer.conf'.format(issuer_type)
             logger.info('Loading %s', source)
             pki.util.load_properties(source, config)
 
@@ -1742,7 +1742,7 @@ class ACMERealmModifyCLI(pki.cli.CLI):
             pki.server.subsystem.ACME_REALM_CLASSES.get(realm_type))
 
         if orig_realm_type != realm_type:
-            source = '/usr/share/pki/acme/realm/{0}/realm.conf'.format(realm_type)
+            source = '/usr/local/share/pki/acme/realm/{0}/realm.conf'.format(realm_type)
             logger.info('Loading %s', source)
             pki.util.load_properties(source, config)
 
