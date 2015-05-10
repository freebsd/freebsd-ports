--- osquery/database/db_handle.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/database/db_handle.cpp
@@ -50,6 +50,10 @@ FLAG_ALIAS(bool, use_in_memory_database,
 DBHandle::DBHandle(const std::string& path, bool in_memory) {
   options_.create_if_missing = true;
   options_.create_missing_column_families = true;
+  options_.info_log_level = rocksdb::WARN_LEVEL;
+  options_.log_file_time_to_roll = 0;
+  options_.keep_log_file_num = 10;
+  options_.max_log_file_size = 1024 * 1024 * 1;
 
   if (in_memory) {
     // Remove when MemEnv is included in librocksdb
