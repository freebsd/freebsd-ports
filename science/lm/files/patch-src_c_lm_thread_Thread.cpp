--- src/c/lm/thread/Thread.cpp.orig	2018-09-09 19:28:35 UTC
+++ src/c/lm/thread/Thread.cpp
@@ -40,6 +40,7 @@
 #include <pthread.h>
 #include "lm/Print.h"
 #include "lm/thread/Thread.h"
+#include <pthread_np.h>
 
 namespace lm {
 namespace thread {
@@ -72,10 +73,10 @@ void Thread::setAffinity(int cpuNumber) 
     if (running)
     {
 		#if defined(LINUX) && !defined(ARM)
-		cpu_set_t cpuset;
+		cpuset_t cpuset;
 		CPU_ZERO(&cpuset);
 		CPU_SET(cpuNumber, &cpuset);
-		if (pthread_setaffinity_np(threadId, sizeof(cpu_set_t), &cpuset) != 0)
+		if (pthread_setaffinity_np(threadId, sizeof(cpuset_t), &cpuset) != 0)
 			Print::printf(Print::WARNING, "Could not bind thread %u to CPU core %d", threadId, cpuNumber);
 		#endif
     }
@@ -100,10 +101,10 @@ void Thread::start() throw(PthreadExcept
         if (cpuNumber >= 0)
         {
 			#if defined(LINUX) && !defined(ARM)
-			cpu_set_t cpuset;
+			cpuset_t cpuset;
 			CPU_ZERO(&cpuset);
 			CPU_SET(cpuNumber, &cpuset);
-			if (pthread_setaffinity_np(threadId, sizeof(cpu_set_t), &cpuset) != 0)
+			if (pthread_setaffinity_np(threadId, sizeof(cpuset_t), &cpuset) != 0)
 				Print::printf(Print::WARNING, "Could not bind thread %u to CPU core %d", threadId, cpuNumber);
 			#endif
         }
