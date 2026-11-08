--- base/acme/src/main/java/org/dogtagpki/acme/realm/PostgreSQLRealm.java.orig	2025-08-05 19:20:05 UTC
+++ base/acme/src/main/java/org/dogtagpki/acme/realm/PostgreSQLRealm.java
@@ -18,7 +18,7 @@ public class PostgreSQLRealm extends PKIPostgreSQLReal
     public void setConfig(RealmConfig config) {
         super.setConfig(config);
         if(config.getParameter("statements") == null) {
-            this.config.setParameter("statements", "/usr/share/pki/acme/realm/postgresql/statements.conf");
+            this.config.setParameter("statements", "/usr/local/share/pki/acme/realm/postgresql/statements.conf");
         }
     }
 
