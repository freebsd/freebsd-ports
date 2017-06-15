databases/leveldb installs the memenv.h header into a different location.

--- Tools/qmake/config.tests/leveldb/leveldb.cpp.orig	2016-09-26 15:03:32 UTC
+++ Tools/qmake/config.tests/leveldb/leveldb.cpp
@@ -19,7 +19,7 @@
 
 #include <leveldb/db.h>
 #include <leveldb/env.h>
-#include <helpers/memenv/memenv.h>
+#include <memenv/memenv.h>
 
 int main(int, char**)
 {
