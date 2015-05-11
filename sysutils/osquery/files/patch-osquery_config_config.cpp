--- osquery/config/config.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/config/config.cpp
@@ -167,7 +167,15 @@ inline void mergeExtraKey(const std::str
     if (node.second.count("") == 0 && conf.all_data.count(name) > 0) {
       conf.all_data.get_child(name).erase(subitem.first);
     }
-    conf.all_data.add_child(name + "." + subitem.first, subitem.second);
+
+    if (subitem.first.size() == 0) {
+      if (conf.all_data.count(name) == 0) {
+        conf.all_data.add_child(name, subitem.second);
+      }
+      conf.all_data.get_child(name).push_back(subitem);
+    } else {
+      conf.all_data.add_child(name + "." + subitem.first, subitem.second);
+    }
   }
 }
 
