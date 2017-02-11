--- src/intel_list.h.orig	2015-12-10 23:29:35.000000000 +0100
+++ src/intel_list.h	2016-10-24 10:22:57.280379000 +0200
@@ -305,8 +305,6 @@
 #define list_last_entry(ptr, type, member) \
     list_entry((ptr)->prev, type, member)
 
-#define __container_of(ptr, sample, member)				\
-    (void *)((char *)(ptr) - ((char *)&(sample)->member - (char *)(sample)))
 /**
  * Loop through the list given by head and set pos to struct in the list.
  *
@@ -325,12 +323,12 @@
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
 
@@ -342,7 +340,7 @@
  * See list_for_each_entry for more details.
  */
 #define list_for_each_entry_safe(pos, tmp, head, member)		\
-    for (pos = __container_of((head)->next, pos, member),		\
+    for (pos = NULL, pos = __container_of((head)->next, pos, member),	\
 	 tmp = __container_of(pos->member.next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = tmp, tmp = __container_of(pos->member.next, tmp, member))
