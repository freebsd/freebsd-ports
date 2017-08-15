--- highwayhash/os_specific.cc.orig	2017-05-08 14:09:02 UTC
+++ highwayhash/os_specific.cc
@@ -40,6 +40,16 @@
 #define OS_LINUX 0
 #endif
 
+#ifdef __FreeBSD__
+#define OS_FREEBSD 1
+#include <sched.h>
+#include <sys/time.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#else
+#define OS_FREEBSD 0
+#endif
+
 #ifdef __MACH__
 #define OS_MAC 1
 #include <mach/mach.h>
@@ -134,6 +144,10 @@ ThreadAffinity* GetThreadAffinity() {
   const int err = cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, pid,
                                      sizeof(cpuset_t), &affinity->set);
   CHECK(err == 0);
+#elif OS_FREEBSD
+  const pid_t pid = 0;  // current thread
+  const int err = cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, pid, sizeof(cpuset_t), &affinity->set);
+  CHECK(err == 0);
 #endif
   return affinity;
 }
@@ -165,6 +179,10 @@ void SetThreadAffinity(ThreadAffinity* a
   const int err = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, pid,
                                      sizeof(cpuset_t), &affinity->set);
   CHECK(err == 0);
+#elif OS_FREEBSD
+  const pid_t pid = 0;  // current thread
+  const int err = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, pid, sizeof(cpuset_t), &affinity->set);
+  CHECK(err == 0);
 #else
 #error "port"
 #endif
@@ -192,6 +210,12 @@ std::vector<int> AvailableCPUs() {
       cpus.push_back(cpu);
     }
   }
+#elif OS_FREEBSD
+  for (size_t cpu = 0; cpu < sizeof(cpuset_t) * 8; ++cpu) {
+    if (CPU_ISSET(cpu, &affinity->set)) {
+      cpus.push_back(cpu);
+    }
+  }
 #else
 #error "port"
 #endif
@@ -208,6 +232,9 @@ void PinThreadToCPU(const int cpu) {
 #elif OS_FREEBSD
   CPU_ZERO(&affinity.set);
   CPU_SET(cpu, &affinity.set);
+#elif OS_FREEBSD
+  CPU_ZERO(&affinity.set);
+  CPU_SET(cpu, &affinity.set);
 #else
 #error "port"
 #endif
