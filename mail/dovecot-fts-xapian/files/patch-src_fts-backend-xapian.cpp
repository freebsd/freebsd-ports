--- src/fts-backend-xapian.cpp.orig	2020-11-02 07:45:52 UTC
+++ src/fts-backend-xapian.cpp
@@ -11,8 +11,8 @@ extern "C" {
 
 #define XAPIAN_FILE_PREFIX "xapian-indexes"
 #define XAPIAN_TERM_SIZELIMIT 245
-#define XAPIAN_COMMIT_ENTRIES 1000000
-#define XAPIAN_COMMIT_TIMEOUT 300
+#define XAPIAN_COMMIT_ENTRIES 1000000L
+#define XAPIAN_COMMIT_TIMEOUT 300L
 #define XAPIAN_COMMIT_MEMORY 10240
 #define XAPIAN_WILDCARD "wldcrd"
 #define XAPIAN_EXPUNGE_SIZE 3
