In file included from Source/Lib/Codec/EbEncDecProcess.c:9:
In file included from Source/Lib/Codec/EbTransforms.h:14:
In file included from Source/Lib/Codec/EbSequenceControlSet.h:10:
Source/Lib/Codec/EbThreads.h:100:11: error: unknown type name 'cpu_set_t'
extern    cpu_set_t                   groupAffinity;
          ^

--- Source/Lib/Common/Codec/EbThreads.h.orig	2019-09-18 21:33:26 UTC
+++ Source/Lib/Common/Codec/EbThreads.h
@@ -99,8 +99,15 @@ extern "C" {
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
+#ifdef __FreeBSD__
+#define cpu_set_t cpuset_t
+#else
 #include <sched.h>
+#endif
 #include <pthread.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 extern    cpu_set_t                   group_affinity;
 #define EB_CREATE_THREAD(pointer, thread_function, thread_context) \
     do { \
