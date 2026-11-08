-- Skip journal_redis storage mode in tests.  fakeredis in FreeBSD Ports does not
-- implement the Redis EVAL command that JournalRedisBackend uses, so these tests
-- fail/crash under xdist.
--- optuna/testing/storages.py.orig	2026-08-03 23:48:41 UTC
+++ optuna/testing/storages.py
@@ -36,7 +36,6 @@ STORAGE_MODES: list[Any] = [
     "sqlite",
     "cached_sqlite",
     "journal",
-    "journal_redis",
     "grpc_rdb",
     "grpc_journal_file",
 ]
