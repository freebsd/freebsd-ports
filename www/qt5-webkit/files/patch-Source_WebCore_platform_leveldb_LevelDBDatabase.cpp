databases/leveldb installs the memenv.h header into a different location.

--- Source/WebCore/platform/leveldb/LevelDBDatabase.cpp.orig	2016-09-26 15:03:55 UTC
+++ Source/WebCore/platform/leveldb/LevelDBDatabase.cpp
@@ -38,7 +38,7 @@
 #include <leveldb/comparator.h>
 #include <leveldb/db.h>
 #include <leveldb/env.h>
-#include <helpers/memenv/memenv.h>
+#include <memenv/memenv.h>
 #include <leveldb/slice.h>
 #include <string>
 #include <wtf/PassOwnPtr.h>
