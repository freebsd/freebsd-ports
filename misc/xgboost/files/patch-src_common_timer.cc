--- src/common/timer.cc.orig	2019-12-14 20:35:26 UTC
+++ src/common/timer.cc
@@ -44,8 +44,9 @@ std::vector<Monitor::StatMap> Monitor::CollectFromOthe
     statistic[kv.first] = Object();
     auto& j_pair = statistic[kv.first];
     j_pair["count"] = Integer(kv.second.count);
-    j_pair["elapsed"] = Integer(std::chrono::duration_cast<std::chrono::microseconds>(
-        kv.second.timer.elapsed).count());
+    // https://github.com/dmlc/xgboost/issues/5117
+    j_pair["elapsed"] = 1; //Integer(std::chrono::duration_cast<std::chrono::microseconds>(
+        //kv.second.timer.elapsed).count());
   }
 
   std::stringstream ss;
