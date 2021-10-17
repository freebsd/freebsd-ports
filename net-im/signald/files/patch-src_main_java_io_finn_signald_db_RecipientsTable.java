--- src/main/java/io/finn/signald/db/RecipientsTable.java.orig	2021-10-17 08:41:09 UTC
+++ src/main/java/io/finn/signald/db/RecipientsTable.java
@@ -144,6 +144,16 @@ public class RecipientsTable {
 
     if (storedUUID == null) {
       storedUUID = getRegisteredUser(e164);
+      if (rowid < 0 && storedUUID != null && queryUUID == null) {
+        statement.setString(1, storedUUID.toString());
+        statement.setString(2, null);
+        rows = statement.executeQuery();
+        if (rows.next()) {
+          rowid = rows.getInt(ROW_ID);
+          update(E164, e164, rowid);
+        }
+      }
+
       if (rowid > 0) {
         update(UUID, storedUUID.toString(), rowid);
       } else {
