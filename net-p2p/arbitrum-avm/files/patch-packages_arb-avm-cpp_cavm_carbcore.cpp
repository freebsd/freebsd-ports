--- packages/arb-avm-cpp/cavm/carbcore.cpp.orig	2022-01-14 20:19:18 UTC
+++ packages/arb-avm-cpp/cavm/carbcore.cpp
@@ -362,7 +362,7 @@ Uint256Result arbCoreLogsCursorGetPosition(CArbCore* a
     auto cursor_index = receiveUint256(index_ptr);
     try {
         auto count_result = arb_core->logsCursorPosition(
-            intx::narrow_cast<size_t>(cursor_index));
+            narrow_cast<size_t>(cursor_index));
         if (!count_result.status.ok()) {
             return {{}, false};
         }
@@ -381,7 +381,7 @@ int arbCoreLogsCursorRequest(CArbCore* arbcore_ptr,
 
     try {
         auto status = arbcore->logsCursorRequest(
-            intx::narrow_cast<size_t>(cursor_index), count);
+            narrow_cast<size_t>(cursor_index), count);
 
         return status;
     } catch (const std::exception& e) {
@@ -399,7 +399,7 @@ IndexedDoubleByteSliceArrayResult arbCoreLogsCursorGet
 
     try {
         auto result =
-            arbcore->logsCursorGetLogs(intx::narrow_cast<size_t>(cursor_index));
+            arbcore->logsCursorGetLogs(narrow_cast<size_t>(cursor_index));
         if (!result.status.ok()) {
             if (!result.status.IsTryAgain()) {
                 std::cerr << "Error getting logs from logs cursor: "
@@ -450,7 +450,7 @@ int arbCoreLogsCursorConfirmReceived(CArbCore* arbcore
 
     try {
         auto status = arbcore->logsCursorConfirmReceived(
-            intx::narrow_cast<size_t>(cursor_index));
+            narrow_cast<size_t>(cursor_index));
 
         return status;
     } catch (const std::exception& e) {
@@ -466,7 +466,7 @@ int arbCoreLogsCursorCheckError(CArbCore* arbcore_ptr,
 
     try {
         return arbcore->logsCursorCheckError(
-            intx::narrow_cast<size_t>(cursor_index));
+            narrow_cast<size_t>(cursor_index));
     } catch (const std::exception& e) {
         std::cerr << "Exception while checking error for logscursor "
                   << e.what() << std::endl;
@@ -482,7 +482,7 @@ char* arbCoreLogsCursorClearError(CArbCore* arbcore_pt
 
     try {
         auto str = arbcore->logsCursorClearError(
-            intx::narrow_cast<size_t>(cursor_index));
+            narrow_cast<size_t>(cursor_index));
 
         if (str.empty()) {
             return nullptr;
