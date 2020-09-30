--- src/operators/rx.cc.orig	2020-01-13 13:09:28 UTC
+++ src/operators/rx.cc
@@ -38,7 +38,6 @@ bool Rx::init(const std::string &arg, st
 
 bool Rx::evaluate(Transaction *transaction, Rule *rule,
     const std::string& input, std::shared_ptr<RuleMessage> ruleMessage) {
-    std::list<SMatch> matches;
     Regex *re;
 
     if (m_param.empty() && !m_string->m_containsMacro) {
@@ -52,29 +51,29 @@ bool Rx::evaluate(Transaction *transacti
         re = m_re;
     }
 
-    matches = re->searchAll(input);
+    std::vector<Utils::SMatchCapture> captures;
+    re->searchOneMatch(input, captures);
+
     if (rule && rule->m_containsCaptureAction && transaction) {
-        int i = 0;
-        matches.reverse();
-        for (const SMatch& a : matches) {
+        for (const Utils::SMatchCapture& capture : captures) {
+            const std::string capture_substring(input.substr(capture.m_offset,capture.m_length));
             transaction->m_collections.m_tx_collection->storeOrUpdateFirst(
-                std::to_string(i), a.str());
+                std::to_string(capture.m_group), capture_substring);
             ms_dbg_a(transaction, 7, "Added regex subexpression TX." +
-                std::to_string(i) + ": " + a.str());
-            transaction->m_matched.push_back(a.str());
-            i++;
+                std::to_string(capture.m_group) + ": " + capture_substring);
+            transaction->m_matched.push_back(capture_substring);
         }
     }
 
-    for (const auto & i : matches) {
-        logOffset(ruleMessage, i.offset(), i.str().size());
+    for (const auto & capture : captures) {
+        logOffset(ruleMessage, capture.m_offset, capture.m_length);
     }
 
     if (m_string->m_containsMacro) {
         delete re;
     }
 
-    if (matches.size() > 0) {
+    if (captures.size() > 0) {
         return true;
     }
 
