--- packages/arb-avm-cpp/data_storage/src/arbcore.cpp.orig	2022-01-14 20:20:15 UTC
+++ packages/arb-avm-cpp/data_storage/src/arbcore.cpp
@@ -3063,7 +3063,7 @@ rocksdb::Status ArbCore::handleLogsCursorReorg(size_t 
                    log_count) {
             // Only part of the data needs to be removed
             auto logs_to_keep =
-                intx::narrow_cast<long>(log_count - current_count_result.data);
+                narrow_cast<long>(log_count - current_count_result.data);
             logs_cursors[cursor_index].data.erase(
                 logs_cursors[cursor_index].data.begin() + logs_to_keep,
                 logs_cursors[cursor_index].data.end());
