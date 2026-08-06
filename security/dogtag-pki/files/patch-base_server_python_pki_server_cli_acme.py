--- base/server/python/pki/server/cli/acme.py.orig	2025-08-05 19:20:05 UTC
+++ base/server/python/pki/server/cli/acme.py
@@ -437,7 +437,7 @@ class ACMEMetadataShowCLI(pki.cli.CLI):
         config = {}
 
         if not os.path.exists(metadata_conf):
-            source = '/usr/share/pki/acme/conf/metadata.conf'
+            source = '/usr/local/share/pki/acme/conf/metadata.conf'
         else:
             source = metadata_conf
 
@@ -524,7 +524,7 @@ class ACMEMetadataModifyCLI(pki.cli.CLI):
         config = {}
 
         if not os.path.exists(metadata_conf):
-            source = '/usr/share/pki/acme/conf/metadata.conf'
+            source = '/usr/local/share/pki/acme/conf/metadata.conf'
         else:
             source = metadata_conf
 
@@ -810,7 +810,7 @@ class ACMEDatabaseModifyCLI(pki.cli.CLI):
             pki.server.subsystem.ACME_DATABASE_CLASSES.get(database_type))
 
         if orig_database_type != database_type:
-            source = '/usr/share/pki/acme/database/{0}/database.conf'.format(database_type)
+            source = '/usr/local/share/pki/acme/database/{0}/database.conf'.format(database_type)
             logger.info('Loading %s', source)
             pki.util.load_properties(source, config)
 
@@ -1143,7 +1143,7 @@ class ACMEIssuerModifyCLI(pki.cli.CLI):
             pki.server.subsystem.ACME_ISSUER_CLASSES.get(issuer_type))
 
         if orig_issuer_type != issuer_type:
-            source = '/usr/share/pki/acme/issuer/{0}/issuer.conf'.format(issuer_type)
+            source = '/usr/local/share/pki/acme/issuer/{0}/issuer.conf'.format(issuer_type)
             logger.info('Loading %s', source)
             pki.util.load_properties(source, config)
 
@@ -1488,7 +1488,7 @@ class ACMERealmModifyCLI(pki.cli.CLI):
             pki.server.subsystem.ACME_REALM_CLASSES.get(realm_type))
 
         if orig_realm_type != realm_type:
-            source = '/usr/share/pki/acme/realm/{0}/realm.conf'.format(realm_type)
+            source = '/usr/local/share/pki/acme/realm/{0}/realm.conf'.format(realm_type)
             logger.info('Loading %s', source)
             pki.util.load_properties(source, config)
 
