--- cpucounters.cpp
+++ cpucounters.cpp
@@ -1617,7 +1617,7 @@ class CoreTaskQueue
     CoreTaskQueue(CoreTaskQueue &) = delete;
 public:
     CoreTaskQueue(int32 core) :
-        worker([&]() {
+        worker([=]() {
             TemporalThreadAffinity tempThreadAffinity(core);
             std::unique_lock<std::mutex> lock(m);
             while (1) {
