--- test/apps/iodemo/io_demo.cc.orig	2026-09-09 16:04:04 UTC
+++ test/apps/iodemo/io_demo.cc
@@ -20,6 +20,7 @@
 #include <ctime>
 #include <csignal>
 #include <cerrno>
+#include <random>
 #include <vector>
 #include <map>
 #include <queue>
@@ -3032,8 +3033,10 @@ static int do_client(options_t& test_opts)
     LOG << "random seed: " << test_opts.random_seed;
 
     // randomize servers to optimize startup
-    std::random_shuffle(test_opts.servers.begin(), test_opts.servers.end(),
-                        IoDemoRandom::urand<size_t>);
+    {
+        std::mt19937 rng(static_cast<uint32_t>(test_opts.random_seed));
+        std::shuffle(test_opts.servers.begin(), test_opts.servers.end(), rng);
+    }
 
     UcxLog vlog(LOG_PREFIX, test_opts.verbose);
     vlog << "List of servers:";
