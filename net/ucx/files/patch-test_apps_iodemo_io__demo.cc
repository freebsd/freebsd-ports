--- test/apps/iodemo/io_demo.cc.orig	2026-02-04 09:52:46 UTC
+++ test/apps/iodemo/io_demo.cc
@@ -18,6 +18,7 @@
 #include <ctime>
 #include <csignal>
 #include <cerrno>
+#include <random>
 #include <vector>
 #include <map>
 #include <queue>
@@ -2999,8 +3000,10 @@ static int do_client(options_t& test_opts)
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
