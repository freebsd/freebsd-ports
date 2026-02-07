Index: gkrellm-gkfreq.c
diff -u -p gkrellm-gkfreq.c.orig gkrellm-gkfreq.c
--- gkrellm-gkfreq.c.orig	2013-08-14 01:42:27.666135000 +0900
+++ gkrellm-gkfreq.c	2013-08-15 16:15:30.727531073 +0900
@@ -36,6 +36,9 @@
 #include <sys/time.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 
 
 // Version of the plugin
@@ -87,6 +90,10 @@ struct GKFreqStruct{
     GkrellmDecal  *label_cpu;
     gint          freq;
     GkrellmDecal  *label_freq;
+#ifdef __FreeBSD__
+    int           oid_freq[CTL_MAXNAME + 2];
+    size_t        oid_freq_len;
+#endif
 };
 
 static GkrellmMonitor *monitor;
@@ -102,6 +109,14 @@ static gint      num_cpu; // number of C
 // Get the CPU frequency (in MHz) for CPU number i
 static gint get_cpu_freq(gint i)
 {
+#ifdef __FreeBSD__
+  int freq;
+  size_t len = sizeof(freq);
+
+  if (sysctl(cpu[i].oid_freq, cpu[i].oid_freq_len, &freq, &len, 0, 0) < 0)
+    return -1;
+  return freq;
+#else
   FILE *f;
   gchar filename[100];
   sprintf(filename, "/sys/devices/system/cpu/cpu%d/cpufreq/scaling_cur_freq",i);
@@ -113,6 +128,7 @@ static gint get_cpu_freq(gint i)
     fclose(f);
     return freq/1000;
   }
+#endif
 }
 
 // Callback function to be run when a panel is exposed for the first time.
@@ -220,7 +236,16 @@ static void create_plugin(GtkWidget *vbo
   // Count the number of CPUs
   if (first_create) {
     for (num_cpu=0; num_cpu<MAX_NUM_CPU; num_cpu++){
-      if (get_cpu_freq(num_cpu) < 0) {
+#ifdef __FreeBSD__
+      gchar mib[16];
+      snprintf(mib, sizeof(mib), "dev.cpu.%d.freq", num_cpu);
+      cpu[num_cpu].oid_freq_len = sizeof(cpu[num_cpu].oid_freq);
+      if (sysctlnametomib(mib, cpu[num_cpu].oid_freq,
+			  &cpu[num_cpu].oid_freq_len) < 0)
+#else
+      if (get_cpu_freq(num_cpu) < 0)
+#endif
+      {
         break;
       }
     }
