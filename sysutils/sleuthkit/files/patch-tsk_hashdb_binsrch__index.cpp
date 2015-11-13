--- tsk/hashdb/binsrch_index.cpp.orig	2015-09-16 17:07:12 UTC
+++ tsk/hashdb/binsrch_index.cpp
@@ -23,7 +23,7 @@
 // the hash, so there are 2 ^ 12 or 4096 possible entries.
 static const size_t IDX_IDX_ENTRY_COUNT = 4096;
 static const size_t IDX_IDX_SIZE = IDX_IDX_ENTRY_COUNT * sizeof(uint64_t);
-static const uint64_t IDX_IDX_ENTRY_NOT_SET = 0xFFFFFFFFFFFFFFFF;
+static const uint64_t IDX_IDX_ENTRY_NOT_SET = 0xFFFFFFFFFFFFFFFFULL;
 
 
 /**
