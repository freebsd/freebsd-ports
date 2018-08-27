--- src/madness/world/thread.cc.orig	2018-08-24 00:32:22 UTC
+++ src/madness/world/thread.cc
@@ -44,6 +44,8 @@
 #include <madness/world/atomicint.h>
 #include <cstring>
 #include <fstream>
+#include <sys/param.h>
+#include <sys/cpuset.h>
 
 #if defined(HAVE_IBMBGQ) and defined(HPM)
 extern "C" unsigned int HPM_Prof_init_thread(void);
@@ -248,8 +250,8 @@ namespace madness {
             }
         }
 
-#ifndef ON_A_MAC
-        cpu_set_t mask;
+#if !defined(ON_A_MAC) && !defined(__FreeBSD__) // need to port to FreeBSD
+        cpuset_t mask;
         CPU_ZERO(&mask);
         for (int i=lo; i<=hi; ++i) CPU_SET(i,&mask);
         if (sched_setaffinity(0, sizeof(mask), &mask) == -1) {
