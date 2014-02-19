--- cpu-miner.c.bak	2014-02-19 09:20:56.187720557 +0100
+++ cpu-miner.c	2014-02-19 09:21:15.296719054 +0100
@@ -75,7 +75,7 @@
 	cpuset_t set;
 	CPU_ZERO(&set);
 	CPU_SET(cpu, &set);
-	cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_CPUSET, -1, sizeof(cpuset_t), &set);
+	cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, -1, sizeof(cpuset_t), &set);
 }
 #else
 static inline void drop_policy(void)
