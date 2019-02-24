In file included from Source/Lib/Codec/EbEncDecProcess.c:9:
In file included from Source/Lib/Codec/EbTransforms.h:14:
In file included from Source/Lib/Codec/EbSequenceControlSet.h:10:
Source/Lib/Codec/EbThreads.h:100:11: error: unknown type name 'cpu_set_t'
extern    cpu_set_t                   groupAffinity;
          ^

--- Source/Lib/Codec/EbThreads.h.orig	2019-02-14 00:36:54 UTC
+++ Source/Lib/Codec/EbThreads.h
@@ -95,7 +95,14 @@ extern    EB_BOOL                  alternateGroups;
 #else
 #define __USE_GNU
 #define _GNU_SOURCE
+#ifdef __FreeBSD__
+#define cpu_set_t cpuset_t
+#else
 #include <sched.h>
+#endif
 #include <pthread.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 extern    cpu_set_t                   groupAffinity;
 #define EB_CREATETHREAD(type, pointer, nElements, pointerClass, threadFunction, threadContext) \
