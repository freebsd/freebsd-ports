--- ./golded3/gesrch.cpp.orig	Mon Oct 20 03:15:28 2003
+++ ./golded3/gesrch.cpp	Mon Oct 20 03:16:29 2003
@@ -217,7 +217,7 @@
 
 bool golded_search_manager::search(GMsg* msg, bool quick, bool shortcircuit) {
 
-  search_item* item = items.begin();
+  vector<search_item>::iterator item = items.begin();
   bool exit = false;
   bool and_cycle = false;
   bool or_cycle = false;
