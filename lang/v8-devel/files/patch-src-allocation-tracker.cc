--- src/allocation-tracker.cc.orig	2014-06-03 08:52:11 UTC
+++ src/allocation-tracker.cc
@@ -152,8 +152,8 @@ void AddressToTraceMap::Clear() {
 void AddressToTraceMap::Print() {
   PrintF("[AddressToTraceMap (%" V8PRIuPTR "): \n", ranges_.size());
   for (RangeMap::iterator it = ranges_.begin(); it != ranges_.end(); ++it) {
-    PrintF("[%p - %p] => %u\n", it->second.start, it->first,
-        it->second.trace_node_id);
+    PrintF("[%p - %p] => %u\n", reinterpret_cast<void*>(it->second.start),
+        reinterpret_cast<void*>(it->first), it->second.trace_node_id);
   }
   PrintF("]\n");
 }
