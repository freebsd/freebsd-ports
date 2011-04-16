--- a/command/decoder.cpp
+++ b/command/decoder.cpp
@@ -6,7 +6,12 @@
  */
 
 #include <stdint.h>
+#ifndef __FreeBSD__
 #include <sched.h>
+#else
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include <errno.h>
 #include <sys/types.h>
 #include <string.h>
@@ -107,6 +112,7 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
     noticeERRMP2=false;
     noticeERRAC3=false;
 
+#ifndef __FreeBSD__
     cpu_set_t cpumask;
     uint len = sizeof(cpumask);
     int cpucount;
@@ -118,6 +124,12 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
     {
         cpucount=CPU_COUNT(&cpumask);
     }
+#else
+    int cpucount;
+    size_t cpus_size = sizeof(cpucount);
+    if (sysctlbyname("hw.ncpu", &cpucount, &cpus_size, NULL, 0) == -1)
+        cpucount = 1;
+#endif
 
     if (Threads==-1)
     {
