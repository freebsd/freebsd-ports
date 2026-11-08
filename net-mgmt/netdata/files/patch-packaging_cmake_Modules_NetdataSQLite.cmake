--- packaging/cmake/Modules/NetdataSQLite.cmake.orig	2026-09-16 20:09:17 UTC
+++ packaging/cmake/Modules/NetdataSQLite.cmake
@@ -37,7 +37,7 @@ function(netdata_bundle_sqlite3)
         else()
                 message(STATUS "Fetching SQLite via tarball")
                 set(SQLITE_FETCH_ARGS
-                        URL "https://www.sqlite.org/${SQLITE_VERSION_YEAR}/sqlite-src-${SQLITE_VERSION_NUMBER}.zip"
+                        URL "%%SQLITE_ARCHIVE%%"
                         URL_HASH "SHA256=${SQLITE_TARBALL_SHA256}"
                 )
         endif()
