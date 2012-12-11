--- ./cpuinfo.c.orig	2012-09-11 08:15:54.000000000 +0200
+++ ./cpuinfo.c	2012-12-11 14:41:28.000000000 +0100
@@ -147,6 +147,7 @@
     printf("Socket-%d [num of cpus %d physical %d logical %d] %s\n",socket->socket_num,socket->max_cpu,socket->num_physical_cores,socket->num_logical_cores,socket_list);
 }
 
+#ifdef __linux__
 void construct_CPU_Heirarchy_info(struct cpu_heirarchy_info* chi)
 {
     int i;
@@ -193,7 +194,50 @@
     chi->max_online_cpu = it_processor_num+1;
 
 }
+#elif __FreeBSD__
+void construct_CPU_Heirarchy_info(struct cpu_heirarchy_info* chi)
+{
+    int i;
+    FILE *fp = fopen("/var/run/dmesg.boot", "r");
+    char strinfo[200];
+    char *tmp;
+
+    int processor_num, physicalid_num = 0, coreid_num = 0;
+    int ncpu = 0, packages, cores, threads;
+
+    if (fp!=NULL) {
+        while ( fgets(strinfo,200,fp) != NULL) {
+            if (strstr(strinfo, "FreeBSD/SMP: ") != NULL) {
+                if ((tmp = strstr(strinfo, "Multiprocessor System Detected: ")) != NULL) {
+                    tmp = strchr(tmp, ':');
+                    tmp++; /* skip space */
+                    ncpu = atoi(tmp);
+                } else {
+                    tmp = strchr(strinfo, ' ');
+                    tmp++; /* skip space */
+                    packages = atoi(tmp);
+                    tmp = strchr(tmp, 'x');
+                    tmp++; /* skip space */
+                    cores = atoi(tmp);
+                    threads = ncpu / (packages * cores);
+                }
+            }
+        }
+        for (i = 0; i < ncpu; i++) {
+            processor_num = i;
+            if ((coreid_num + 1) == cores)
+                physicalid_num++;
+            physicalid_num %= packages;
+            coreid_num = processor_num % cores;
 
+            chi->processor_num[i] = processor_num;
+            chi->package_num[i] = physicalid_num;
+            chi->coreid_num[i] = coreid_num;
+        }
+    }
+    chi->max_online_cpu = ncpu;
+}
+#endif
 void print_CPU_Heirarchy(struct cpu_heirarchy_info chi)
 {
     int i;
