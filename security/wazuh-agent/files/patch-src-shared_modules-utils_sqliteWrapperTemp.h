--- src/shared_modules/utils/sqliteWrapperTemp.h	2025-11-07 00:46:03.000000000 -0800
+++ src/shared_modules/utils/sqliteWrapperTemp.h	2026-01-01 13:52:11.656050000 -0800
@@ -235,8 +235,8 @@
         public:
             ~Connection() = default;
 
-            explicit Connection(const std::string& path)
-                : m_db{ openSQLiteDb(path), [](sqlite3 * p)
+            explicit Connection(const std::string& path, const int flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE)
+                : m_db{ openSQLiteDb(path, flags), [](sqlite3 * p)
             {
                 sqlite3_close_v2(p);
             } }
@@ -245,7 +245,10 @@
 
                 if (path.compare(DB_MEMORY) != 0)
                 {
-                    const auto result { chmod(path.c_str(), DB_PERMISSIONS) };
+                    const auto result =
+                        (flags == SQLITE_OPEN_READONLY)
+                            ? 0
+                            : chmod(path.c_str(), DB_PERMISSIONS);
 
                     if (result != 0)
                     {
@@ -255,7 +258,7 @@
                         };
                     }
 
-                    m_db.reset(openSQLiteDb(path, SQLITE_OPEN_READWRITE), [](sqlite3 * p)
+                    m_db.reset(openSQLiteDb(path, flags), [](sqlite3 * p)
                     {
                         sqlite3_close_v2(p);
                     });
