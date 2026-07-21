--- base/server/src/main/java/com/netscape/cms/servlet/csadmin/LDAPConfigurator.java.orig	2025-08-05 19:20:05 UTC
+++ base/server/src/main/java/com/netscape/cms/servlet/csadmin/LDAPConfigurator.java
@@ -97,34 +97,34 @@ public class LDAPConfigurator {
 
     public void configureServer() throws Exception {
         logger.info("Configuring DS server");
-        importLDIF("/usr/share/pki/server/database/ds/config.ldif", true);
+        importLDIF("/usr/local/share/pki/server/database/ds/config.ldif", true);
     }
 
     public void setupSchema() throws Exception {
         logger.info("Setting up PKI schema");
-        importSchemaFile("/usr/share/pki/server/database/ds/schema.ldif");
+        importSchemaFile("/usr/local/share/pki/server/database/ds/schema.ldif");
     }
 
     public void createContainers(String subsystem) throws Exception {
         logger.info("Creating container entries");
-        importLDIF("/usr/share/pki/" + subsystem + "/database/ds/create.ldif", true);
+        importLDIF("/usr/local/share/pki/" + subsystem + "/database/ds/create.ldif", true);
     }
 
     public void setupACL(String subsystem) throws Exception {
         logger.info("Setting up ACL");
-        importLDIF("/usr/share/pki/" + subsystem + "/database/ds/acl.ldif", true);
+        importLDIF("/usr/local/share/pki/" + subsystem + "/database/ds/acl.ldif", true);
     }
 
     public void createIndexes(String subsystem) throws Exception {
         logger.info("Creating indexes");
-        importLDIF("/usr/share/pki/" + subsystem + "/database/ds/index.ldif", true);
+        importLDIF("/usr/local/share/pki/" + subsystem + "/database/ds/index.ldif", true);
     }
 
     public void rebuildIndexes(String subsystem) throws Exception {
 
         logger.info("Rebuilding indexes");
 
-        File file = new File("/usr/share/pki/" + subsystem + "/database/ds/indextasks.ldif");
+        File file = new File("/usr/local/share/pki/" + subsystem + "/database/ds/indextasks.ldif");
         File tmpFile = File.createTempFile("pki-" + subsystem + "-reindex-", ".ldif");
 
         try {
@@ -151,7 +151,7 @@ public class LDAPConfigurator {
         Map<String, String> params = new HashMap<>();
         params.put("dbuser", dn);
 
-        importLDIF("/usr/share/pki/server/database/ds/db-access-grant.ldif", true, params);
+        importLDIF("/usr/local/share/pki/server/database/ds/db-access-grant.ldif", true, params);
     }
 
     public void revokeDatbaseAccess(String dn) throws Exception {
@@ -161,7 +161,7 @@ public class LDAPConfigurator {
         Map<String, String> params = new HashMap<>();
         params.put("dbuser", dn);
 
-        importLDIF("/usr/share/pki/server/database/ds/db-access-revoke.ldif", true, params);
+        importLDIF("/usr/local/share/pki/server/database/ds/db-access-revoke.ldif", true, params);
     }
 
     public List<LDAPEntry> findVLVs() throws Exception {
@@ -190,7 +190,7 @@ public class LDAPConfigurator {
 
     public void addVLVs(String subsystem) throws Exception {
         logger.info("Add VLVs");
-        importLDIF("/usr/share/pki/" + subsystem + "/database/ds/vlv.ldif", true);
+        importLDIF("/usr/local/share/pki/" + subsystem + "/database/ds/vlv.ldif", true);
     }
 
     public void deleteVLVs() throws Exception {
@@ -211,7 +211,7 @@ public class LDAPConfigurator {
         logger.info("Reindex VLVs");
 
         Collection<LDIFRecord> records = importLDIF(
-                "/usr/share/pki/" + subsystem + "/database/ds/vlvtasks.ldif", false);
+                "/usr/local/share/pki/" + subsystem + "/database/ds/vlvtasks.ldif", false);
 
         for (LDIFRecord record : records) {
             String dn = record.getDN();
