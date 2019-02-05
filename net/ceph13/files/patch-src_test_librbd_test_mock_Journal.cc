diff --git a/src/test/librbd/test_mock_Journal.cc b/src/test/librbd/test_mock_Journal.cc
index c21f7e3e3b..a6ce5e9d28 100644
--- src/test/librbd/test_mock_Journal.cc
+++ src/test/librbd/test_mock_Journal.cc
@@ -482,7 +482,7 @@ public:
     expect_get_max_append_size(mock_journaler, 1 << 16);
     expect_start_replay(
       mock_image_ctx, mock_journaler,
-      std::bind(&invoke_replay_complete, _1, 0));
+      std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
 
     MockJournalReplay mock_journal_replay;
     expect_stop_replay(mock_journaler);
@@ -531,7 +531,7 @@ TEST_F(TestMockJournal, StateTransitions) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_ready, _1));
+    std::bind(&invoke_replay_ready, std::placeholders::_1));
 
   ::journal::MockReplayEntry mock_replay_entry;
   MockJournalReplay mock_journal_replay;
@@ -540,11 +540,11 @@ TEST_F(TestMockJournal, StateTransitions) {
   expect_try_pop_front(mock_image_ctx, mock_journaler, true, mock_replay_entry);
   expect_replay_process(mock_journal_replay);
   expect_try_pop_front(mock_image_ctx, mock_journaler, false, mock_replay_entry,
-                       std::bind(&invoke_replay_ready, _1));
+                       std::bind(&invoke_replay_ready, std::placeholders::_1));
   expect_try_pop_front(mock_image_ctx, mock_journaler, true, mock_replay_entry);
   expect_replay_process(mock_journal_replay);
   expect_try_pop_front(mock_image_ctx, mock_journaler, false, mock_replay_entry,
-                       std::bind(&invoke_replay_complete, _1, 0));
+                       std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
 
   expect_stop_replay(mock_journaler);
   expect_shut_down_replay(mock_image_ctx, mock_journal_replay, 0);
@@ -601,7 +601,7 @@ TEST_F(TestMockJournal, ReplayCompleteError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_complete, _1, -EINVAL));
+    std::bind(&invoke_replay_complete, std::placeholders::_1, -EINVAL));
 
   MockJournalReplay mock_journal_replay;
   expect_stop_replay(mock_journaler);
@@ -616,7 +616,7 @@ TEST_F(TestMockJournal, ReplayCompleteError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_complete, _1, 0));
+    std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
 
   expect_stop_replay(mock_journaler);
   expect_shut_down_replay(mock_image_ctx, mock_journal_replay, 0);
@@ -649,14 +649,14 @@ TEST_F(TestMockJournal, FlushReplayError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_ready, _1));
+    std::bind(&invoke_replay_ready, std::placeholders::_1));
 
   ::journal::MockReplayEntry mock_replay_entry;
   MockJournalReplay mock_journal_replay;
   expect_try_pop_front(mock_image_ctx, mock_journaler, true, mock_replay_entry);
   expect_replay_process(mock_journal_replay);
   expect_try_pop_front(mock_image_ctx, mock_journaler, false, mock_replay_entry,
-                       std::bind(&invoke_replay_complete, _1, 0));
+                       std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
   expect_stop_replay(mock_journaler);
   expect_shut_down_replay(mock_image_ctx, mock_journal_replay, -EINVAL);
   expect_flush_commit_position(mock_journaler);
@@ -669,7 +669,7 @@ TEST_F(TestMockJournal, FlushReplayError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_complete, _1, 0));
+    std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
 
   expect_stop_replay(mock_journaler);
   expect_shut_down_replay(mock_image_ctx, mock_journal_replay, 0);
@@ -702,7 +702,7 @@ TEST_F(TestMockJournal, CorruptEntry) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_ready, _1));
+    std::bind(&invoke_replay_ready, std::placeholders::_1));
 
   ::journal::MockReplayEntry mock_replay_entry;
   MockJournalReplay mock_journal_replay;
@@ -720,7 +720,7 @@ TEST_F(TestMockJournal, CorruptEntry) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_complete, _1, 0));
+    std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
   expect_stop_replay(mock_journaler);
   expect_shut_down_replay(mock_image_ctx, mock_journal_replay, 0);
   expect_flush_commit_position(mock_journaler);
@@ -752,7 +752,7 @@ TEST_F(TestMockJournal, StopError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_complete, _1, 0));
+    std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
 
   MockJournalReplay mock_journal_replay;
   expect_stop_replay(mock_journaler);
@@ -786,7 +786,7 @@ TEST_F(TestMockJournal, ReplayOnDiskPreFlushError) {
 
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_ready, _1));
+    std::bind(&invoke_replay_ready, std::placeholders::_1));
 
   ::journal::MockReplayEntry mock_replay_entry;
   MockJournalReplay mock_journal_replay;
@@ -813,7 +813,7 @@ TEST_F(TestMockJournal, ReplayOnDiskPreFlushError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler, {
-      std::bind(&invoke_replay_complete, _1, 0)
+      std::bind(&invoke_replay_complete, std::placeholders::_1, 0)
     });
 
   expect_stop_replay(mock_journaler);
@@ -868,14 +868,14 @@ TEST_F(TestMockJournal, ReplayOnDiskPostFlushError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_ready, _1));
+    std::bind(&invoke_replay_ready, std::placeholders::_1));
 
   ::journal::MockReplayEntry mock_replay_entry;
   MockJournalReplay mock_journal_replay;
   expect_try_pop_front(mock_image_ctx, mock_journaler, true, mock_replay_entry);
   expect_replay_process(mock_journal_replay);
   expect_try_pop_front(mock_image_ctx, mock_journaler, false, mock_replay_entry,
-                       std::bind(&invoke_replay_complete, _1, 0));
+                       std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
   expect_stop_replay(mock_journaler);
 
   Context *on_flush = nullptr;
@@ -892,7 +892,7 @@ TEST_F(TestMockJournal, ReplayOnDiskPostFlushError) {
   expect_get_max_append_size(mock_journaler, 1 << 16);
   expect_start_replay(
     mock_image_ctx, mock_journaler,
-    std::bind(&invoke_replay_complete, _1, 0));
+    std::bind(&invoke_replay_complete, std::placeholders::_1, 0));
 
   expect_stop_replay(mock_journaler);
   expect_shut_down_replay(mock_image_ctx, mock_journal_replay, 0);
