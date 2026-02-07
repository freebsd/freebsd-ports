Source/Lib/Codec/EbEncHandle.c:1531:5: error: use of undeclared identifier 'cpu_set_t'
Source/Lib/Codec/EbThreads.h:102:62: note: expanded from macro 'EB_CREATETHREAD'
        pthread_setaffinity_np(*((pthread_t*)pointer),sizeof(cpu_set_t),&group_affinity); \
                                                             ^

--- Source/Lib/Codec/EbThreads.h.orig	2019-09-06 19:42:45 UTC
+++ Source/Lib/Codec/EbThreads.h
@@ -93,6 +93,18 @@ extern    uint64_t         *total_lib_memory;         
     } \
     lib_thread_count++;
 #elif defined(__linux__)
+#define __USE_GNU
+#define _GNU_SOURCE
+#ifdef __FreeBSD__
+#define cpu_set_t cpuset_t
+#else
+#include <sched.h>
+#endif
+#include <pthread.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+extern    cpu_set_t                   group_affinity;
 #define EB_CREATETHREAD(type, pointer, n_elements, pointer_class, thread_function, thread_context) \
     pointer = eb_create_thread(thread_function, thread_context); \
     if (pointer == (type)EB_NULL) { \
