--- OrthancServer/Sources/Database/PrepareDatabase.sql.orig	2025-08-11 16:02:50 UTC
+++ OrthancServer/Sources/Database/PrepareDatabase.sql
@@ -160,4 +160,9 @@ -- The "1" corresponds to the "GlobalProperty_Database
 
 -- Set the version of the database schema
 -- The "1" corresponds to the "GlobalProperty_DatabaseSchemaVersion" enumeration
-INSERT INTO GlobalProperties VALUES (1, "6");
+-- Upstream code has (1, "6"), which causes startup to fail on FreeBSD
+-- E1023 08:43:05.328003             MAIN Connection.cpp:169] SQLite execute error: no such column: "6" - should this be a string literal in single-quotes? (1)
+-- Apparently due to sqlite 3.41+ being stricter about string literals
+-- Debian packages currently uses 3.34
+-- https://orthanc.uclouvain.be/bugs/show_bug.cgi?id=227
+INSERT INTO GlobalProperties VALUES (1, 6);
