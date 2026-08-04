-- Skip Redis journal storage tests.  fakeredis in FreeBSD Ports does not
-- implement the Redis EVAL command that JournalRedisBackend uses, so these
-- tests fail/crash.
--- tests/storages_tests/journal_tests/test_journal.py.orig	2026-08-04 00:02:22 UTC
+++ tests/storages_tests/journal_tests/test_journal.py
@@ -33,11 +33,9 @@ LOG_STORAGE_WITH_PARAMETER = [
     ("file_with_open_lock", None),
     ("file_with_link_lock", 30),
     ("file_with_link_lock", None),
-    ("redis_default", None),
-    ("redis_with_use_cluster", None),
 ]
 
-JOURNAL_STORAGE_SUPPORTING_SNAPSHOT = ["journal_redis"]
+JOURNAL_STORAGE_SUPPORTING_SNAPSHOT = []
 
 
 class JournalLogStorageSupplier:
