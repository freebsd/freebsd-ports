--- minisat/core/Solver.cc.orig	2018-01-25 10:02:23.823406000 +0100
+++ minisat/core/Solver.cc	2018-01-25 10:02:40.248326000 +0100
@@ -992,11 +992,11 @@
 {
     double cpu_time = cpuTime();
     double mem_used = memUsedPeak();
-    printf("restarts              : %"PRIu64"\n", starts);
-    printf("conflicts             : %-12"PRIu64"   (%.0f /sec)\n", conflicts   , conflicts   /cpu_time);
-    printf("decisions             : %-12"PRIu64"   (%4.2f %% random) (%.0f /sec)\n", decisions, (float)rnd_decisions*100 / (float)decisions, decisions   /cpu_time);
-    printf("propagations          : %-12"PRIu64"   (%.0f /sec)\n", propagations, propagations/cpu_time);
-    printf("conflict literals     : %-12"PRIu64"   (%4.2f %% deleted)\n", tot_literals, (max_literals - tot_literals)*100 / (double)max_literals);
+    printf("restarts              : %" PRIu64"\n", starts);
+    printf("conflicts             : %-12" PRIu64"   (%.0f /sec)\n", conflicts   , conflicts   /cpu_time);
+    printf("decisions             : %-12" PRIu64"   (%4.2f %% random) (%.0f /sec)\n", decisions, (float)rnd_decisions*100 / (float)decisions, decisions   /cpu_time);
+    printf("propagations          : %-12" PRIu64"   (%.0f /sec)\n", propagations, propagations/cpu_time);
+    printf("conflict literals     : %-12" PRIu64"   (%4.2f %% deleted)\n", tot_literals, (max_literals - tot_literals)*100 / (double)max_literals);
     if (mem_used != 0) printf("Memory used           : %.2f MB\n", mem_used);
     printf("CPU time              : %g s\n", cpu_time);
 }
