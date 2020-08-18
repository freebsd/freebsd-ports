kgem.c:2864:22: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry(bo, &kgem->snoop, list) {
                            ^~
../../src/intel_list.h:328:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:2849:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo, *first = NULL;
                          ^
                           = NULL
kgem.c:3118:27: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
                                 ^~
../../src/intel_list.h:345:45: note: expanded from macro 'list_for_each_entry_safe'
    for (pos = __container_of((head)->next, pos, member),               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:3115:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo, *next;
                          ^
                           = NULL
kgem.c:3429:27: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry_safe(bo, next, &rq->buffers, request) {
                                 ^~
../../src/intel_list.h:345:45: note: expanded from macro 'list_for_each_entry_safe'
    for (pos = __container_of((head)->next, pos, member),               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:3425:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo, *next;
                          ^
                           = NULL
kgem.c:3541:27: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
                                 ^~
../../src/intel_list.h:345:45: note: expanded from macro 'list_for_each_entry_safe'
    for (pos = __container_of((head)->next, pos, member),               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:3539:24: note: initialize the variable 'bo' to silence this warning
        struct kgem_buffer *bo, *next;
                              ^
                               = NULL
kgem.c:3930:22: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry(bo, list, list) {
                            ^~
../../src/intel_list.h:328:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:3928:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo;
                          ^
                           = NULL
kgem.c:4670:23: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
                list_for_each_entry(bo, cache, vma) {
                                    ^~
../../src/intel_list.h:328:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:4576:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo, *first = NULL;
                          ^
                           = NULL
kgem.c:5411:31: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
                list_for_each_entry_reverse(bo, &kgem->scanout, list) {
                                            ^~
../../src/intel_list.h:333:45: note: expanded from macro 'list_for_each_entry_reverse'
    for (pos = __container_of((head)->prev, pos, member);               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:5380:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo;
                          ^
                           = NULL
kgem.c:7225:22: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry(bo, buffers, request) {
                            ^~
../../src/intel_list.h:328:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:7223:20: note: initialize the variable 'bo' to silence this warning
        struct kgem_bo *bo;
                          ^
                           = NULL
kgem.c:7517:22: error: variable 'bo' is uninitialized when used here [-Werror,-Wuninitialized]
        list_for_each_entry(bo, &kgem->batch_buffers, base.list) {
                            ^~
../../src/intel_list.h:328:45: note: expanded from macro 'list_for_each_entry'
    for (pos = __container_of((head)->next, pos, member);               \
                                            ^~~
../../src/intel_list.h:309:41: note: expanded from macro '__container_of'
    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
                                        ^~~~~~
kgem.c:7503:24: note: initialize the variable 'bo' to silence this warning
        struct kgem_buffer *bo;
                              ^
                               = NULL

--- src/intel_list.h.orig	2019-02-21 22:26:50 UTC
+++ src/intel_list.h
@@ -325,12 +325,12 @@ list_is_empty(const struct list *head)
  *
  */
 #define list_for_each_entry(pos, head, member)				\
-    for (pos = __container_of((head)->next, pos, member);		\
+    for (pos = NULL, pos = __container_of((head)->next, pos, member);	\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.next, pos, member))
 
-#define list_for_each_entry_reverse(pos, head, member)				\
-    for (pos = __container_of((head)->prev, pos, member);		\
+#define list_for_each_entry_reverse(pos, head, member)			\
+    for (pos = NULL, pos = __container_of((head)->prev, pos, member);	\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.prev, pos, member))
 
@@ -342,7 +342,7 @@ list_is_empty(const struct list *head)
  * See list_for_each_entry for more details.
  */
 #define list_for_each_entry_safe(pos, tmp, head, member)		\
-    for (pos = __container_of((head)->next, pos, member),		\
+    for (pos = NULL, pos = __container_of((head)->next, pos, member),	\
 	 tmp = __container_of(pos->member.next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = tmp, tmp = __container_of(pos->member.next, tmp, member))
