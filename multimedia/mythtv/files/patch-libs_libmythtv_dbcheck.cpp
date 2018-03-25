Database schema 1347 fails to update due to bad SQL statement
Ref: https://code.mythtv.org/trac/ticket/13155

--- libs/libmythtv/dbcheck.cpp.orig	2018-02-01 11:15:37 UTC
+++ libs/libmythtv/dbcheck.cpp
@@ -3340,25 +3340,24 @@ NULL
 
     if (dbver == "1346")
     {
-        QString master;
+        QList<QByteArray> updates_ba;
         // Create new MasterServerName setting
         if (gCoreContext->IsMasterHost())
-            master =
-            "insert into settings (value,data,hostname) "
-            "values('MasterServerName','"
-                + gCoreContext->GetHostName() + "', null);";
+            updates_ba.push_back(
+                QString("INSERT INTO settings (value, data, hostname) "
+                        "VALUES ('MasterServerName', '%1', NULL);")
+                        .arg(gCoreContext->GetHostName()).toLocal8Bit());
         else
-            master =
-            "insert into settings (value,data,hostname) "
-            "select 'MasterServerName', b.hostname, null "
-            "from settings a, settings b "
-            "where a.value = 'MasterServerIP' "
-            "and b.value in ('BackendServerIP','BackendServerIP6')"
-            "and a.data = b.data;";
+            updates_ba.push_back(
+                QString("INSERT INTO settings (value,data,hostname) "
+                        "SELECT 'MasterServerName', b.hostname, NULL "
+                        "FROM settings a, settings b "
+                        "WHERE a.value = 'MasterServerIP' "
+                        "AND b.value IN ('BackendServerIP','BackendServerIP6')"
+                        "AND a.data = b.data;")
+                        .toLocal8Bit());
 
-        const char *updates[] = {
-            // Create new MasterServerName setting
-            master.toLocal8Bit().constData(),
+        const char *post_sql[] = {
             // Create new BackendServerAddr setting for each backend server
             // Assume using IPV4 value.
             "insert into settings (value,data,hostname) "
@@ -3385,8 +3384,17 @@ NULL
             // Delete obsolete settings
             "delete from settings "
                 "where value in ('WatchTVGuide');",
-            NULL
         };
+        
+        for (uint i = 0; i < sizeof(post_sql)/sizeof(char*); i++)
+            updates_ba.push_back(QByteArray(post_sql[i]));
+
+        // Convert update ByteArrays to NULL terminated char**
+        QList<QByteArray>::const_iterator it = updates_ba.begin();
+        vector<const char*> updates;
+        for (; it != updates_ba.end(); ++it)
+            updates.push_back((*it).constData());
+        updates.push_back(NULL);
 
         if (!performActualUpdate(&updates[0], "1347", dbver))
             return false;
